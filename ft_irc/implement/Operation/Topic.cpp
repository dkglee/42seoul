#include "../../header/Topic.hpp"
#include "../../header/Exception.hpp"
#include <cstring>

void TopicOperation::setTopic(std::string n) {
	this->topic = n;
}

int TopicOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executer = ru_list.find(fd);
	if (chs[executer->second.getChannel()].getTopicFlag() && !executer->second.isOP()) {
		throw OperationException(OPERATIONEXCEPTION, "You have No Permission.");
	} else {
		chs[executer->second.getChannel()].setTopic(topic);
		std::vector<int> usersSocket = chs[executer->second.getChannel()].getUserSocketList();
		const char* msg = "Please check as the topic has been newly set. - from channel operator.\n";
		for (std::vector<int>::iterator it = usersSocket.begin(); it != usersSocket.end(); it++) {
			sock_tool->sendMsg(*it, msg);
		}
	}
	return 0;
}

TopicOperation::~TopicOperation() {}
