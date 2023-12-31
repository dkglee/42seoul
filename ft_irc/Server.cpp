#include "./header/Server.hpp"

Server::Server(const char* port, const char* pw) {
	this->port = atoi(port);
	this->pw = atoi(pw);
}

Server::~Server() {
	for (std::map<int, User>::iterator it = running_user_lists.begin(); it != running_user_lists.end(); it++) {
		close(it->first);
	}
	close(serv_sock.getSocket());
	std::memset(fds, 0, sizeof(fds));
}

void Server::init(int servSock) {
	memset(fds, 0, sizeof(fds));
	fds[0].fd = servSock;
	fds[0].events = POLLIN;
	nfds = 1;
}

void Server::removeUser(int fd) {
	r_list::iterator user = running_user_lists.find(fd);
	if (user != running_user_lists.end()) {
		chs[user->second.getChannel()].removeUser(user->second.getNick());
		running_user_lists.erase(user);
	}
}

void Server::runServer() {
	serv_sock = sock_tool->createSocket(port);
	
	if (listen(serv_sock.getSocket(), 5) == -1) {
		// err
	}
	init(serv_sock.getSocket());
	
	int retval;

	Socket cli_sock;
	int str_len;
	std::cout << port << ' ' << pw << std::endl;
	std::cout << "socket: " << serv_sock.getSocket() << std::endl;;
	
	while (server_running) {
		if ((retval = poll(fds, nfds, 5000)) <= 0) {
			if (retval == -1) {
				std::cerr << "poll error: " << std::endl;
			} else if (retval == 0) {
				std::cerr << "time out" << std::endl;
			}
		} else {
			if (fds[0].revents & POLLIN) {
				cli_sock = sock_tool->accepSocket(fds[0].fd);
				// 최적화 할 예정
				std::cout << "Client is Trying to Connect" << std::endl;
				send(cli_sock.getSocket(), "give me a password\n", strlen("give me a password\n"), 0);
				for (int i = 0; i < POLL_SIZE; i++) {
					if (fds[i].fd == 0) {
						std::cout << "Client is set in POLL" << std::endl;
						fds[i].fd = cli_sock.getSocket();
						fds[i].events = POLLIN;
						nfds += 1;
						break ;
					}
				}
			} else {
				for (int i = 1; i < POLL_SIZE; i++) {
					if (fds[i].revents & POLLIN) {
						try {
							op_tool = parse_tool.parseBuf(fds[i].fd, running_user_lists, backup_user_lists);
							op_tool->runOperation(chs, running_user_lists, backup_user_lists, fds[i].fd, pw);
							delete op_tool;
						} catch (MyException& e) {
							switch (e.getErrCode()) {
							std::cerr << e.what() << std::endl;
							case EXITEXCEPTION :
								removeUser(fds[i].fd);
								std::cout << "Client[" << fds[i].fd << "] exits server." << std::endl;
								close(fds[i].fd);
								nfds -= 1;
								std::memset(&fds[i], 0, sizeof(fds[i]));
								break ;
							case OPERATIONEXCEPTION :
								sock_tool->sendMsg(fds[i].fd, e.what());
								delete op_tool;
								break ;
							default:
								sock_tool->sendMsg(fds[i].fd, e.what());
								break ;
							}
						}
					}
				}
			}
		}
	}
}
