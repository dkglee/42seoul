#include "../../header/AuthOperation.hpp"

void AuthOperation::setValue(std::string val, int offset) {
	AuthPtr arr[3] = {&AuthOperation::password, &AuthOperation::userName, &AuthOperation::nickName};
	(this->*arr[offset]) = val;
}

void AuthOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd) {
	
}

AuthOperation::~AuthOperation() {}
