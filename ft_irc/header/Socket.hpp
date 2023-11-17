#ifndef SOCKET_IO
# define SOCKET_IO

// file system all
#include <fcntl.h>
// socket
#include <sys/socket.h>
// TCP
#include <netinet/in.h>
#include <arpa/inet.h>
// stl
#include <string>

class Socket {
private:
	int sockNum;
	socklen_t adr_sz;
	struct sockaddr_in sock_adr;
public:
	Socket createSocket(int port);
	Socket accepSocket(int fd);
	int getSocket();
};

#endif
