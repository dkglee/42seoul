#include "../../header/Topic.hpp"

void TopicOperation::setTopic(std::string n) {
	this->topic = n;
}

int TopicOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executer = ru_list.find(fd);
	// User를 관리하는 채널에게 User의 Socket을 부여해야 금방 찾을듯.
	if ()
}

TopicOperation::~TopicOperation() {}
