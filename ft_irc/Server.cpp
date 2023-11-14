#include "./header/Server.hpp"

Server::Server(const char* port, const char* pw) {
	this->port = atoi(port);
	this->pw = atoi(pw);
}

void Server::init(int servSock) {
	memset(fds, 0, sizeof(fds));
	fds[0].fd = servSock;
	fds[0].events = POLLIN;
}

void Server::runServer() {
	int servSock = sock_tool.createSocket(port);
	if (listen(servSock, 5));

	init(servSock);

}
