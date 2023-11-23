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
IOperation* AuthCreator::factoryMethod(std::vector<std::string>& parsed) {
	if (parsed.size() != 3) {
		// send Message Keep auth form
		return NULL;
	}
	AuthOperation* ret = new AuthOperation();
	ret->setValue(parsed[0], parsed[1], parsed[2]);
	return ret;
}

AuthCreator::~AuthCreator() {}

IOperation* OpKickCreator::factoryMethod(std::vector<std::string>& parsed) {
	if (parsed.size() != 2) {
		// Should be 2 args
		return NULL;
	}
	KickOperation* ret = new KickOperation();
	ret->setNickname(parsed[1]);
	return ret;
}

OpKickCreator::~OpKickCreator() {}

IOperation* OpInviteCreator::factoryMethod(std::vector<std::string>& parsed) {
	if (parsed.size() != 2) {
		// Should be 2 args
		return NULL;
	}
	InviteOperation* ret = new InviteOperation();
	ret->setNickname(parsed[1]);
	return ret;
}

OpInviteCreator::~OpInviteCreator() {}

IOperation* OpTopicCreator::factoryMethod(std::vector<std::string>& parsed) {
	TopicOperation* ret = new TopicOperation();
	std::vector<std::string> topic(parsed.begin() + 1, parsed.end());
	std::string strTopic = s_tool->makeString(topic);
	ret->setTopic(strTopic);
	return ret;
}

OpTopicCreator::~OpTopicCreator() {}

IOperation* OpModeCreator::factoryMethod(std::vector<std::string>& parsed) {
	ModeOperation* ret = new ModeOperation();
	if (parsed.size() > 3) {
		// Should be 2 or 3
		return NULL;
	}
	if (parsed[1][0] != '-') {
		// Should start with '-'
		return NULL;
	}
	if (parsed[1].size() == 2) {
		if (parsed.size() == 3) {
			ret->setMode(parsed[1][1], parsed[2]);
		} else {
			ret->setMode(parsed[1][1]);
		}
	}
	return ret;
}

OpModeCreator::~OpModeCreator() {}

IOperation* JoinCreator::factoryMethod(std::vector<std::string>& parsed) {
	JoinOperation* ret = new JoinOperation();
	if (parsed.size() > 2)
		ret->setJoin(parsed[1], parsed[2]);
	else
		ret->setJoin(parsed[1], "");
	return ret;
}

JoinCreator::~JoinCreator() {}

IOperation* MessageCreator::factoryMethod(std::vector<std::string>& parsed) {
	MessageOperation* ret = new MessageOperation();
	std::string temp = s_tool->makeString(parsed);
	ret->setMessage(temp);
	return ret;
}

MessageCreator::~MessageCreator() {}
