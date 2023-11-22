#include "../../header/Join.hpp"
#include <cstring>

void JoinOperation::setJoin(std::string chn, std::string key) {
	this->channel = chn;
	this->key = key;
}

bool JoinOperation::authUser(Channel* chs, r_list::iterator executor) {
	int iKey = atoi(key.c_str());
	if (chs[atoi(channel.c_str())].authenticateUser(iKey))
		return true;
	return false;
}

void JoinOperation::broadcast(Channel* chs, r_list::iterator executor, int channel) {
	std::vector<int> list = chs[channel].getUserSocketList();
	std::string sendMsg("User ");
	sendMsg = sendMsg + executor->second.getNick();
	sendMsg = sendMsg + " has joined this channel.\n";
	for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
		send(*it, sendMsg.c_str(), strlen(sendMsg.c_str()), 0);
	}
}

// 채널이 공홈에 있어야 함 -> 실행자 스스로 해당 채널에 들어가려고 함. -> (이때 비밀번호가 설정되어 있다면 비번을 입력해야함) 만약 해당 채널에 아무런 인원이 없다면 OP로 들어가게 됨.
int JoinOperation::runOperation(Channel* chs, r_list& ru_list, b_list& bu_list, int fd, int key) {
	r_list::iterator executor = ru_list.find(fd);
	int toJoinChannel = atoi(channel.c_str());
	if (executor->second.getChannel() != 0) {
		// executor should be in Channel 0
	}
	if (chs[toJoinChannel].getUserSocketList().size() == 0) {
		executor->second.setChannel(toJoinChannel);
		chs[toJoinChannel].addUser(executor->first, executor->second.getNick());
		chs[0].removeUser(executor->second.getNick());
		executor->second.setOP();
		broadcast(chs, executor, toJoinChannel);
	} else {
		if (authUser(chs, executor)) {
			executor->second.setChannel(toJoinChannel);
			chs[0].removeUser(executor->second.getNick());
			chs[toJoinChannel].addUser(executor->first, executor->second.getNick());
			broadcast(chs, executor, toJoinChannel);
		}
	}
	std::string topic = chs[toJoinChannel].getTopic();
	if (topic.size() != 0) {
		send(executor->first, topic.c_str(), strlen(topic.c_str()), 0);
	}
	return 0;
}

JoinOperation::~JoinOperation() {}
