#include "../../header/Message.hpp"
#include <cstring>

void MessageOperation::setMessage(std::string msg) {
	this->msg = msg;
}

void MessageOperation::broadcast(Channel* chs, r_list::iterator executor) {
	std::string sendMsg(executor->second.getNick());
	sendMsg = sendMsg + ": " + msg + '\n';
	std::vector<int> list = chs[executor->second.getChannel()].getUserSocketList();
	for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
		send(*it, sendMsg.c_str(), strlen(sendMsg.c_str()), 0);
	}
}

int MessageOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	broadcast(chs, ru_list.find(fd));
	return 0;
}

MessageOperation::~MessageOperation() {}
