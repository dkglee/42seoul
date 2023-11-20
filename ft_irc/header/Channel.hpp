#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <vector>
#include <string>
#include <utility>

class Channel {
private:
	// flag
	bool inviteFlag;
	bool keyFlag;
	bool topicFlag;
	// info
	int ulimit;
	std::string topic;
	std::vector<std::pair<int, std::string> > users;
	int key;
public:
	void addUser(int socket, std::string);
	void removeUser(std::string);
	void setTopic(std::string);
	std::vector<int> getUserSocketList();
};

#endif
