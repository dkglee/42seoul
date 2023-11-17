#include "../../header/Factory.hpp"
#include "../../header/AuthOperation.hpp"

IOperation* AuthCreator::factoryMethod(char* buf, int buf_size) {
	// split 후 각각에 원하는 정보를 담기.
	// 예외 케이스 및 에러 처리 할것.
	AuthOperation* ret = new AuthOperation();
	int args = 0;
	int i = 0, j = 0;
	std::string temp(buf);
	while (i <= j && j <= temp.size()) {
		if (temp[j] == ' ' || temp[j] == '|' || j == temp.size()) {
			std::string parsed(temp.begin() + i, temp.begin() + j);
			ret->setValue(parsed, args);
			args += 1;
			while (temp[j] != ' ' || temp[j] == '|' && j != temp.size()) {
				j++;
			}
			i = j;
		}
	}
	if (args == 2) {
		ret->setValue("0", 3);
	}
	return ret;
}

AuthCreator::~AuthCreator() {}

IOperation* OpKickCreator::factoryMethod(char* buf, int buf_size) {

}

OpKickCreator::~OpKickCreator() {}

IOperation* OpInviteCreator::factoryMethod(char* buf, int buf_size) {

}

OpInviteCreator::~OpInviteCreator() {}

IOperation* OpTopicCreator::factoryMethod(char* buf, int buf_size) {

}

OpTopicCreator::~OpTopicCreator() {}

IOperation* OpModeCreator::factoryMethod(char* buf, int buf_size) {

}

OpModeCreator::~OpModeCreator() {}

IOperation* JoinCreator::factoryMethod(char* buf, int buf_size) {

}

JoinCreator::~JoinCreator() {}

IOperation* MessageCreator::factoryMethod(char* buf, int buf_size) {

}

MessageCreator::~MessageCreator() {}
