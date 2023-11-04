#include <iostream>
#include <poll.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>

#define BUF_SIZE 100
#define POLL_SIZE 100

void accept_loop(int sock) {
	char buf[BUF_SIZE];
	int listening_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	
	listening_sock = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(sock);

	if (bind(listening_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1) {
		std::cerr << "bind() error";
		return ;
	}
	if (listen(listening_sock, 5) == -1) {
		std::cerr << "listen() error";
		return ;
	}

	struct sockaddr_in myaddr;
	memset(&myaddr, 0, sizeof(myaddr));


	struct pollfd fds[POLL_SIZE];
	memset(fds, 0, sizeof(fds));
	fds[0].fd = listening_sock;
	fds[0].events = POLLIN | POLLPRI;

	int nfds = 1;

	socklen_t adr_sz;
	
	adr_sz = sizeof(listening_sock);
	getsockname(listening_sock, (struct sockaddr*)&myaddr, &adr_sz);
	std::cout << "Port : " << ntohs(myaddr.sin_port) << std::endl;
	std::cout << "Address : " << inet_ntoa(myaddr.sin_addr) << std::endl;

	int str_len;
	int retval;
	while (1) {
		if ((retval = poll(fds, nfds, 5000)) <= 0) {
			if (retval == -1) {
				std::cerr << "poll error: " << strerror(errno) << std::endl;
			} else if (retval == 0) {
				std::cerr << "time out" << std::endl;
			}
		} else {
			if (fds[0].revents & (POLLIN | POLLPRI)) {
				adr_sz = sizeof(clnt_adr);
				clnt_sock = accept(listening_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
				for (int i = 1; i < POLL_SIZE; i++) {
					if (fds[i].fd == 0) {
						fds[i].fd = clnt_sock;
						fds[i].events = POLLIN | POLLPRI;
						nfds++;
						std::cout << "Client fd[" << i << "] is connected" << std::endl;
						break ;
					}
				}
			}
			for (int i = 1; i < POLL_SIZE; i++) {
				if (fds[i].revents & (POLLIN | POLLPRI)) {
					str_len = recv(fds[i].fd, buf, BUF_SIZE, 0);
					if (str_len == 0) {
						// close(fds[i].fd);
						// fds[i].fd = 0;
						// fds[i].events = 0;
						// nfds--;
						for (int i = 1; i < POLL_SIZE; i++) {
							if (fds[i].fd != 0) {
								close(fds[i].fd);
							}
						}
						close(listening_sock);
						return ;
					} else {
						std::cout << "fd[" << i << "]" << buf << std::endl;
						for (int i = 1; i < POLL_SIZE; i++) {
							if (fds[i].fd != 0) {
								send(fds[i].fd, buf, str_len, 0);
							}
						}
						std::memset(buf, 0, sizeof(buf));
					}
				}
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int sock = atoi(argv[1]);
	accept_loop(sock);
	return 0;
}
