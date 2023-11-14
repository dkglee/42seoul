#ifndef SERVER_HPP
# define SERVER_HPP

// std in/out
#include <iostream>
// stl
#include <vector>
#include <map>
#include <string>
#include <algorithm>
// poll
#include <poll.h>
// socket
#include <sys/socket.h>
#include <Socket.hpp>
// TCP
#include <netinet/in.h>
#include <arpa/inet.h>
// // file system call
// #include <fcntl.h>
// etc
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
// signal
#include <signal.h>

// Constant
# define BUFF_SIZE 1500
# define POLL_SIZE 100
# define CHANNEL_SIZE 1000

// use default destructor
class Server {
private:
	int port;
	int pw;
	int nfds;
	struct pollfd fds[1000];
	std::vector<Channel> chs[CHANNEL_SIZE];
	Socket sock_tool;
	Server(const Server&);
	Server operator=(const Server&);
	void init(int);
public:
	Server(const char*, const char*);
	void runServer();
};

#endif
