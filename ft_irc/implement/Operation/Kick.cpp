#include "../../header/Kick.hpp"
#include "../../header/Exception.hpp"
#include <cstring>

void KickOperation::setNickname(std::string n) {
	this->nickname = n;
}

int KickOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executer = ru_list.find(fd);
	if (!executer->second.isOP()) {
		throw OperationException(OPERATIONEXCEPTION, "You have No Permission.");
	} else {
		r_list::iterator kicked;
		for (kicked = ru_list.begin(); kicked != ru_list.end(); kicked++) {
			if (!nickname.compare(kicked->second.getNick()))
				break ;
		}
		if (kicked != ru_list.end()) {
			kicked->second.kicked();
			chs[executer->second.getChannel()].removeUser(nickname);
			chs[0].addUser(kicked->first, nickname);
			const char* msg = "You are kicked from the Channel.";
			sock_tool->sendMsg(kicked->first, msg);
		} else {
			throw OperationException(OPERATIONEXCEPTION, "There is No User in this Channel.");
		}
	}
	return 0;
}

KickOperation::~KickOperation() {}
