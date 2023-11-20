#include "../../header/Mode.hpp"
#include <cstring>

void ModeOperation::setMode(char c, std::string op) {
	this->mode = c;
	this->operand = op;
}

void ModeOperation::inviteMode(r_list::iterator executor, Channel* chs) {
	if (!chs[executor->second.getChannel()].changeInviteMode()) {
		char *sendMsg = "This Channel is now Invite-Only.";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	} else {
		char *sendMsg = "The Invite-Only mode has been lifted.";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	}
}

void ModeOperation::topicMode(r_list::iterator executor, Channel* chs) {
	if (!chs[executor->second.getChannel()].changeTopicMode()) {
		char *sendMsg = "Topic is now Operator-Only.";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	} else {
		char *sendMsg = "The Operator-Only mode has been lifted.";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	}
}

void ModeOperation::keyMode(r_list::iterator executor, Channel* chs) {
	if (this->operand.empty()) {
		chs[executor->second.getChannel()].changeKeyMode(-1);
		char *sendMsg = "Key is disabled.";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	} else {
		chs[executor->second.getChannel()].changeKeyMode(atoi(this->operand.c_str()));
		char *sendMsg = "Key is set";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	}
}

// 해당 인원을 찾음.
void ModeOperation::operatorMode(r_list::iterator executor, Channel* chs, r_list& ru_list, b_list& bu_list) {
	int OperandSocket = chs[executor->second.getChannel()].findUser(operand);
	if (OperandSocket == -1) {
		// No User in the Channel
	} else {
		r_list::iterator user = ru_list.find(OperandSocket);
		if (user == ru_list.end()) {
			// No User in the Server
		} else {
			if (!user->second.isOP()) {
				user->second.setOP();
				char *sendMsg = "User is now Operator";
				send(executor->first, sendMsg, strlen(sendMsg), 0);
				send(user->first, sendMsg, strlen(sendMsg), 0);
			} else {
				user->second.setOP();
				char *sendMsg = "User is now just Client";
				send(executor->first, sendMsg, strlen(sendMsg), 0);
				send(user->first, sendMsg, strlen(sendMsg), 0);
			}
		}
	}
}

void ModeOperation::limitMode(r_list::iterator executor, Channel* chs) {
	if (this->operand.empty()) {
		chs[executor->second.getChannel()].changeUserLimitMode(-1);
		char *sendMsg = "User is unlimited.";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	} else {
		chs[executor->second.getChannel()].changeUserLimitMode(atoi(this->operand.c_str()));
		char *sendMsg = "User is limited.";
		send(executor->first, sendMsg, strlen(sendMsg), 0);
	}
}

int ModeOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executor = ru_list.find(fd);
	if (!executor->second.isOP()) {
		// No Permission
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
			char* sendMsg = "There is No such Mode";
			send(executor->first, sendMsg, strlen(sendMsg), 0);
		}
	}
}

ModeOperation::~ModeOperation() {}
