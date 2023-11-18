#include "../../header/AuthOperation.hpp"

void AuthOperation::setValue(std::string val, int offset) {
	AuthPtr arr[3] = {&AuthOperation::password, &AuthOperation::userName, &AuthOperation::nickName};
	(this->*arr[offset]) = val;
}

AuthOperation::~AuthOperation() {}
