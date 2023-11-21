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
	bool limitFlag;
	// info
	int ulimit;
	std::string topic;
	// int - socket, string - nickname
	std::vector<std::pair<int, std::string> > users;
	int key;
public:
	void addUser(int socket, std::string);
	void removeUser(std::string);
	void setTopic(std::string);
	std::vector<int> getUserSocketList();
	int findUser(std::string);
	// 추후에 멤버 함수 포인터로 관리해야겠다.
	bool changeInviteMode();
	bool changeTopicMode();
	bool changeKeyMode(int key);
	bool changeUserLimitMode(int num);
	// Auth
	bool authenticateUser(int);
};

#endif
