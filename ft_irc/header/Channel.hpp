#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <vector>
#include <string>

class Channel {
private:
	// flag
	bool inviteFlag;
	bool keyFlag;
	bool topicFlag;
	// info
	int ulimit;
	std::string topic;
	std::vector<std::string> users;
	int key;
};

#endif
