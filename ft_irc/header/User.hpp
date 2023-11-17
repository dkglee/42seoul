#ifndef USER_HPP
# define USER_HPP

// User Socket Info
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
// etc
# include <string>
# include "Socket.hpp"


class User {
private:
// basic User Info
	bool op;
	std::string n_name;
	std::string u_name;
	int assocChannel;
// User Socket Info
	Socket sock_info;
	// struct sockaddr_in user_adr;
};

#endif
