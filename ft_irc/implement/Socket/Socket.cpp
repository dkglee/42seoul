#include "../../header/Socket.hpp"
#include <cstring>

Socket Socket::createSocket(int port) {
	Socket ret;
	ret.sockNum = socket(AF_INET, SOCK_STREAM, 0);
	memset(&ret.sock_adr, 0, sizeof(sock_adr));
	ret.sock_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	ret.sock_adr.sin_port = htons(port);
	ret.adr_sz = sizeof(ret.sock_adr);

	if (bind(ret.sockNum, (struct sockaddr*)&ret.sock_adr, ret.adr_sz) == -1)  {
		// error
		// return ;
	}
	return ret;
}

Socket Socket::accepSocket(int fd) {
	Socket ret;
	ret.adr_sz = sizeof(ret.sock_adr);
	ret.sockNum = accept(fd, (struct sockaddr*)&ret.sock_adr, &(ret.adr_sz));
	return ret;
}

int Socket::getSocket() {
	return this->sockNum;
}

int Socket::readBuff(int fd, char* buf) {
	int strlen = recv(fd, (void *)buf, BUFF_SIZE, 0);
	return strlen;
}
