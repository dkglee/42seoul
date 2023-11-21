#include "../../header/Message.hpp"

void MessageOperation::setMessage(std::string msg) {
	this->msg = msg;
}

int MessageOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	
}

MessageOperation::~MessageOperation() {}
