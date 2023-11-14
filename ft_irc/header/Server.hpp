#ifndef SERVER_HPP
# define SERVER_HPP

// std in/out
# include <iostream>
// stl
# include <vector>
# include <map>
# include <string>
# include <algorithm>
// poll
# include <poll.h>
// socket
# include <sys/socket.h>
# include <Socket.hpp>
// TCP
# include <netinet/in.h>
# include <arpa/inet.h>
// // file system call
// # include <fcntl.h>
// etc
# include <cstring>
# include <stdlib.h>
# include <unistd.h>
// signal
# include <signal.h>
// Channel & User
# include <Channel.hpp>
# include <User.hpp>

// DB
# include <Database.hpp>

// Constant
# define BUFF_SIZE 1500
# define POLL_SIZE 1000
# define CHANNEL_SIZE 1000

// use default destructor
class Server {
private:
	// primitive info
	int port;
	int pw;

	// for Poll()
	int nfds;
	struct pollfd fds[POLL_SIZE];
	void init(int);

	// User & Channels
	Channel chs[CHANNEL_SIZE];
	std::map<std::string, User> user;

	// DB
	Database db_tool;
	
	// tool
	Socket sock_tool;

	// Not Permitted Methods of Creating Instance
	Server(const Server&);
	Server operator=(const Server&);
public:
	Server(const char*, const char*);
	void runServer();
};

#endif
