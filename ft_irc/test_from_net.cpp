void accept_loop(int soc)
{
    char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
    int child[MAX_CHILD];
    struct sockaddr_storage from;
    int acc, child_no, i, j, count, pos, ret;
    socklen_t len;
    struct pollfd targets[MAX_CHILD + 1];
    /* child 배열 초기화 */
    for (i = 0; i < MAX_CHILD; i++) {
        child[i] = -1;
    }
    child_no = 0;
    for (;;) {
        /* poll()용 데이터 작성 */
        count = 0;
        targets[count].fd = soc;
        targets[count].events = POLLIN;
        count++;
        for (i = 0; i < child_no; i++) {
            if (child[i] != -1) {
                targets[count].fd = child[i];
                targets[count].events = POLLIN;
                count++;
            }
        }
        (void) fprintf(stderr,"<<child count:%d>>\n", count - 1);
        switch (poll(targets, count, 10 * 1000)) {
        case -1:
            /* 에러 */
            perror("poll");
            break;
        case 0:
            /* 타임아웃 */
            break;
        default:
            if (targets[0].revents & POLLIN) {
                /* 서버 소켓 ready */
                len = (socklen_t) sizeof(from);
                /* 연결 수락 */
                if ((acc = accept(soc, (struct sockaddr *)&from, &len)) == -1) {
                    if(errno!=EINTR){
                        perror("accept");
                    }
                } else {
                    (void) getnameinfo((struct sockaddr *) &from, len,
                               hbuf, sizeof(hbuf),
                               sbuf, sizeof(sbuf),
                               NI_NUMERICHOST | NI_NUMERICSERV);
                    (void) fprintf(stderr, "accept:%s:%s\n", hbuf, sbuf);
                    /* child 여유 검색 */
                    pos = -1;
                    for (i = 0; i < child_no; i++) {
                        if (child[i] == -1) {
                            pos = i;
                            break;
                        }
                    }
                    if (pos == -1) {
                        /* 여유 없음 */
                        if (child_no + 1 >= MAX_CHILD) {
                            /* child에 더이상 저장 불가 */
                            (void) fprintf(stderr,
                       "child is full : cannot accept\n");
                            /* close */
                            (void) close(acc);
                        } else {
                            child_no++;
                            pos = child_no - 1;
                        }
                    }
                    if (pos != -1) {
                        /* child에 저장 */
                        child[pos] = acc;
                    }
                }
            }
/* 준비 완료된 파일 디스크립터 확인 (계산량 O(n)) */         
            for (i = 1; i < count; i++) {
                if (targets[i].revents & (POLLIN | POLLERR)) {
                    /* 전송 */
                    if ((ret = send_recv(targets[i].fd, i - 1)) == -1) {
                        /* 오류 */
                        /* close */
                        (void) close(targets[i].fd);
                        /* child 비우기 */
                        for (j = 0; j < child_no; j++) {
                            if (child[j] == targets[i].fd) {
                                child[j] = -1;
                                break;
                            }
                        }
                    }
                }
            }
        break;
        }
    }
}
