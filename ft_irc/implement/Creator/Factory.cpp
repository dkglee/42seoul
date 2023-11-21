#include "../../header/Factory.hpp"
#include "../../header/AuthOperation.hpp"
#include "../../header/Kick.hpp"
#include "../../header/Invite.hpp"
#include "../../header/Topic.hpp"
#include "../../header/Mode.hpp"
#include "../../header/Join.hpp"
#include "../../header/Message.hpp"
#include <sstream>
#include <vector>
#include <iostream>

Creator::~Creator() {}

OpCreator::~OpCreator() {}

// 예외 케이스 및 에러 처리 할것.
IOperation* AuthCreator::factoryMethod(char* buf, int buf_size) {
	// split 후 각각에 원하는 정보를 담기.
	AuthOperation* ret = new AuthOperation();
	std::string temp(buf);
	

	std::istringstream iss(temp);
	char delimiter = ' ';
	std::vector<std::string> args;
	std::string temp_buf;
	while (getline(iss, temp_buf, delimiter)) {
		args.push_back(temp_buf);
	}
	std::cout << args.size() << std::endl;
	args[2].erase(args[2].find('\n'));
	ret->setValue(args[0], args[1], args[2]);
	return ret;
}

AuthCreator::~AuthCreator() {}

IOperation* OpKickCreator::factoryMethod(char* buf, int buf_size) {
	KickOperation* ret = new KickOperation();
	std::string temp(buf);
	std::string nick(temp.begin() + 6, temp.end() - 1);
	ret->setNickname(nick);
	return ret;
}

OpKickCreator::~OpKickCreator() {}

IOperation* OpInviteCreator::factoryMethod(char* buf, int buf_size) {
	InviteOperation* ret = new InviteOperation();
	std::string temp(buf);
	std::string nick(temp.begin() + 8, temp.end() - 1);
	ret->setNickname(nick);
	return ret;
}

OpInviteCreator::~OpInviteCreator() {}

IOperation* OpTopicCreator::factoryMethod(char* buf, int buf_size) {
	TopicOperation* ret = new TopicOperation();
	std::string temp(buf);
	std::string topic(temp.begin() + 7, temp.end() - 1);
	ret->setTopic(topic);
	return ret;
}

OpTopicCreator::~OpTopicCreator() {}

IOperation* OpModeCreator::factoryMethod(char* buf, int buf_size) {
	ModeOperation* ret = new ModeOperation();
	std::string temp(buf);
	char mode = temp[7];
	if (temp.size() > 8) {
		std::string operand(temp.begin() + 9, temp.end() - 1);
		ret->setMode(mode, operand);
	} else {
		ret->setMode(mode);
	}
	return ret;
}

OpModeCreator::~OpModeCreator() {}

IOperation* JoinCreator::factoryMethod(char* buf, int buf_size) {
	JoinOperation* ret = new JoinOperation();
	std::string temp(buf);
	std::istringstream iss(temp);
	char delimiter = ' ';
	std::vector<std::string> args;
	std::string temp_buf;
	while (getline(iss, temp_buf, delimiter)) {
		args.push_back(temp_buf);
	}
	args[args.size() - 1].erase(args[args.size() - 1].find('\n'));
	if (args.size() > 2)
		ret->setJoin(args[1], args[2]);
	else
		ret->setJoin(args[1], "");
	return ret;
}

JoinCreator::~JoinCreator() {}

IOperation* MessageCreator::factoryMethod(char* buf, int buf_size) {
	MessageOperation* ret = new MessageOperation();
	std::string temp(buf);
	ret->setMessage(temp);
	return ret;
}

MessageCreator::~MessageCreator() {}
