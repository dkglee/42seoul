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
public:
	int createSocket(int port);
};

#endif
