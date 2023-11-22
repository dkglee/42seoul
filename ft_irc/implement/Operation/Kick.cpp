#include "../../header/Kick.hpp"
#include <cstring>

void KickOperation::setNickname(std::string n) {
	this->nickname = n;
}

int KickOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executer = ru_list.find(fd);
	if (!executer->second.isOP()) {
		const char* msg = "You have no permission.\n";
		send(executer->first, msg, strlen(msg), 0);
		return -1;
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
			const char* msg = "You are kicked from the Channel.\n";
			send(kicked->first, msg, strlen(msg), 0);
		} else {
			const char* msg = "There is no such user.\n";
			send(executer->first, msg, strlen(msg), 0);
			return -1;
		}
	}
	return 0;
}

KickOperation::~KickOperation() {}
