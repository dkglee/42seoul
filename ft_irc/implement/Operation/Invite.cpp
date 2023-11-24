#include "../../header/Invite.hpp"
#include "../../header/Exception.hpp"
#include <cstring>

void InviteOperation::setNickname(std::string n) {
	this->nickname = n;
}

// 추후에 책임 관계를 바꿀 필요가 있을 듯 => Executer는 User에게 직접 묻는게 아니라 Channel에게 해당 유저가 있나요?
// 라고 물을 필요가 있을 것 같다.
int InviteOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executer = ru_list.find(fd);
	if (!executer->second.isOP()) {
		throw OperationException(OPERATIONEXCEPTION, "You have No Permission.");
	} else {
		r_list::iterator invited;
		for (invited = ru_list.begin(); invited != ru_list.end(); invited++) {
			if (!nickname.compare(invited->second.getNick()))
				break ;
		}
		if (invited->second.getChannel() != 0) {
			throw OperationException(OPERATIONEXCEPTION, "User is not in Channel 0.");
		} else if (invited == ru_list.end()) {
			throw OperationException(OPERATIONEXCEPTION, "User is not in Server.");
		} else if (chs[executer->second.getChannel()].isFull()) {
			throw OperationException(OPERATIONEXCEPTION, "Channel is already full.");
		}
		invited->second.setChannel(executer->second.getChannel());
		chs[0].removeUser(nickname);
		chs[executer->second.getChannel()].addUser(invited->first, nickname);
		const char *str = "You are Invited\n";
		sock_tool->sendMsg(invited->first, str);
		std::string topic = chs[invited->second.getChannel()].getTopic();
		if (topic.size() != 0) {
			sock_tool->sendMsg(invited->first, topic.c_str());
		}
	}
	return 0;
}

InviteOperation::~InviteOperation() {}
