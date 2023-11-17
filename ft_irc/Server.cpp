#include "./header/Server.hpp"

Server::Server(const char* port, const char* pw) {
	this->port = atoi(port);
	this->pw = atoi(pw);
}

void Server::init(int servSock) {
	memset(fds, 0, sizeof(fds));
	fds[0].fd = servSock;
	fds[0].events = POLLIN;
	nfds = 1;
}

void Server::runServer() {
	Socket serv_sock = sock_tool->createSocket(port);
	if (listen(serv_sock.getSocket(), 5));

	init(serv_sock.getSocket());
	
	int retval;

	Socket cli_sock;
	int str_len;
	while (1) {
		if ((retval = poll(fds, nfds, 5000)) <= 0) {
			// err
		} else {
			if (fds[0].revents & POLLIN) {
				cli_sock = sock_tool->accepSocket(fds[0].fd);
				// 최적화 할 예정
				for (int i = 0; i < POLL_SIZE; i++) {
					if (fds[i].fd != 0) {
						fds[i].fd = cli_sock.getSocket();
						fds[i].events = POLLIN;
						nfds += 1;
						running_user_lists.insert({fds[i].fd, User()}); // C++98에는 이게 안되나?
						break;
					}
				}
			} else {
				for (int i = 1; i < POLL_SIZE; i++) {
					if (fds[i].revents & POLLIN) {
						op_tool = parse_tool.parseBuf(fds[i].fd, running_user_lists, backup_user_lists);
						op_tool->runOperation(chs, running_user_lists, fds[i].fd);
					}
				}
			}
		}
	}
}
