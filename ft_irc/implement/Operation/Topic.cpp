#include "../../header/Topic.hpp"
#include <cstring>

void TopicOperation::setTopic(std::string n) {
	this->topic = n;
}

int TopicOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executer = ru_list.find(fd);
	if (!executer->second.isOP()) {
		// no Permission
	} else {
		chs[executer->second.getChannel()].setTopic(topic);
		std::vector<int> usersSocket = chs[executer->second.getChannel()].getUserSocketList();
		const char* sendMsg = "Please check as the topic has been newly set. - from channel operator";
		for (std::vector<int>::iterator it = usersSocket.begin(); it != usersSocket.end(); it++) {
			send(*it, sendMsg, strlen(sendMsg), 0);
		}
	}
	return 0;
}

TopicOperation::~TopicOperation() {}
