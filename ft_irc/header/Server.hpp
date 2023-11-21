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
# include "Socket.hpp"
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
# include "Channel.hpp"
# include "User.hpp"

// DB
# include "Database.hpp"

// Constant
// # define BUFF_SIZE 1500
# define POLL_SIZE 1000
# define CHANNEL_SIZE 1000

// Parsing
# include "Parse.hpp"

// Operation
# include "IOperation.hpp"

// # ifndef GLOBAL_SERVER_RUNNING_STATE
// #  define GLOBAL_SERVER_RUNNING_STATE
extern bool server_running;
// # endif

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
	// std::vector<Channel> chs;
	std::map<int, User> running_user_lists;
	std::map<std::string, User> backup_user_lists;

	// DB
	Database* db_tool;
	
	// tool
	Socket* sock_tool;

	// Not Permitted Methods of Creating Instance
	Server(const Server&);
	Server operator=(const Server&);

	// Parse
	Parse parse_tool;

	// Operation Interface
	IOperation* op_tool;
	
public:
	Server(const char*, const char*);
	void runServer();
	~Server();
};

#endif
