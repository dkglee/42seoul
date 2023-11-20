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
	void setNick(std::string);
	void setUser(std::string);
public:
	void setNewUser(bool, std::string, std::string);
	std::string getNick();
	bool isOP();
	void setOP();
	void kicked();
	int getChannel();
	void setChannel(int n);
};

#endif
