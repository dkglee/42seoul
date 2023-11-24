#include "../../header/Mode.hpp"
#include "../../header/Exception.hpp"
#include <cstring>

void ModeOperation::setMode(char c, std::string op) {
	this->mode = c;
	this->operand = op;
}

void ModeOperation::inviteMode(r_list::iterator executor, Channel* chs) {
	if (chs[executor->second.getChannel()].changeInviteMode()) {
		const char* msg = "This Channel is now Invite-Only.";
		sock_tool->sendMsg(executor->first, msg);
	} else {
		const char* msg = "The Invite-Only mode has been lifted.";
		sock_tool->sendMsg(executor->first, msg);
	}
}

void ModeOperation::topicMode(r_list::iterator executor, Channel* chs) {
	if (chs[executor->second.getChannel()].changeTopicMode()) {
		const char* msg = "Topic is now Operator-Only.";
		sock_tool->sendMsg(executor->first, msg);
	} else {
		const char* msg = "The Operator-Only mode has been lifted.";
		sock_tool->sendMsg(executor->first, msg);
	}
}

void ModeOperation::keyMode(r_list::iterator executor, Channel* chs) {
	if (this->operand.empty()) {
		chs[executor->second.getChannel()].changeKeyMode(-1);
		const char* msg = "Key is disabled.";
		sock_tool->sendMsg(executor->first, msg);
	} else {
		chs[executor->second.getChannel()].changeKeyMode(atoi(this->operand.c_str()));
		const char* msg = "Key is set.";
		sock_tool->sendMsg(executor->first, msg);
	}
}

// 해당 인원을 찾음.
void ModeOperation::operatorMode(r_list::iterator executor, Channel* chs, r_list& ru_list, b_list& bu_list) {
	int OperandSocket = chs[executor->second.getChannel()].findUser(operand);
	if (OperandSocket == -1) {
		throw OperationException(OPERATIONEXCEPTION, "There is no such user in this Channel.");
	} else {
		r_list::iterator user = ru_list.find(OperandSocket);
		if (user == ru_list.end()) {
			throw OperationException(OPERATIONEXCEPTION, "There is no such user in this Channel.");
		} else {
			if (!user->second.isOP()) {
				user->second.setOP();
				const char* msg = "User is now Operator.";
				sock_tool->sendMsg(executor->first, msg);
				send(user->first, msg, strlen(msg), 0);
			} else {
				user->second.setOP();
				const char* msg = "User is now just Client.";
				sock_tool->sendMsg(executor->first, msg);
				send(user->first, msg, strlen(msg), 0);
			}
		}
	}
}

void ModeOperation::limitMode(r_list::iterator executor, Channel* chs) {
	if (!(this->operand.empty()) && chs[executor->second.getChannel()].getUserSocketList().size() > atoi(this->operand.c_str())) {
		throw OperationException(OPERATIONEXCEPTION, "The number of Users in this Channel is greater than your limits.");
	} else {
		if (this->operand.empty()) {
			chs[executor->second.getChannel()].changeUserLimitMode(-1);
			const char* msg = "User is unlimited.";
			sock_tool->sendMsg(executor->first, msg);
		} else {
			chs[executor->second.getChannel()].changeUserLimitMode(atoi(this->operand.c_str()));
			const char* msg = "User is limited.";
			sock_tool->sendMsg(executor->first, msg);
		}
	}
}

int ModeOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executor = ru_list.find(fd);
	try {
		if (!executor->second.isOP()) {
			throw OperationException(OPERATIONEXCEPTION, "You have NO Permission.");
		} else {
			switch (mode) {
			case 'i' :
				this->inviteMode(executor, chs);
				break ;
			case 't' :
				this->topicMode(executor, chs);
				break ;
			case 'k' :
				this->keyMode(executor, chs);
				break ;
			case 'o' :
				this->operatorMode(executor, chs, ru_list, bu_list);
				break ;
			case 'l' :
				this->limitMode(executor, chs);
				break ;
			default :
				throw OperationException(OPERATIONEXCEPTION, "There is No such Mode.");
				break ;
			}
		}
	} catch (MyException&) {
		throw ;
	}
	return 0;
}

ModeOperation::~ModeOperation() {}
