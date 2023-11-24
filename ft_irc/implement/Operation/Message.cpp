#include "../../header/Message.hpp"
#include <cstring>

void MessageOperation::setMessage(std::string msg) {
	this->msg = msg;
}

void MessageOperation::broadcast(Channel* chs, r_list::iterator executor) {
	std::string retmsg(executor->second.getNick());
	retmsg = retmsg + ": " + msg;
	std::vector<int> list = chs[executor->second.getChannel()].getUserSocketList();
	for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
		sock_tool->sendMsg(*it, retmsg.c_str());
	}
}

int MessageOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	broadcast(chs, ru_list.find(fd));
	return 0;
}

MessageOperation::~MessageOperation() {}
