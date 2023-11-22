#include "../../header/Channel.hpp"

void Channel::addUser(int socket, std::string user) {
	this->users.push_back({socket, user});
}

void Channel::removeUser(std::string user) {
	for (std::vector<std::pair<int, std::string> >::iterator it = this->users.begin(); it != this->users.end(); it++) {
		if (!it->second.compare(user)) {
			this->users.erase(it);
			break;
		}
	}
}

void Channel::setTopic(std::string topic) {
	this->topic = topic;
}

std::string Channel::getTopic() {
	return this->topic;
}

std::vector<int> Channel::getUserSocketList() {
	std::vector<int> ret(users.size());
	std::vector<std::pair<int, std::string> >::iterator own = users.begin();
	for (std::vector<int>::iterator it = ret.begin(); it != ret.end(); it++) {
		*it = own++->first;
	}
	return ret;
}

bool Channel::changeInviteMode() {
	if (inviteFlag == false) {
		inviteFlag = true;
		return true;
	} else {
		inviteFlag = false;
		return false;
	}
}

bool Channel::changeTopicMode() {
	if (topicFlag == false) {
		topicFlag = true;
		return true;
	} else {
		topicFlag = false;
		return false;
	}
}

bool Channel::changeKeyMode(int key) {
	if (key == -1) {
		return keyFlag = false;
	} else {
		this->key = key;
		return keyFlag = true;
	}
}

bool Channel::changeUserLimitMode(int num) {
	if (num == -1) {
		return limitFlag = false;
	} else {
		this->ulimit = num;
		return limitFlag = true;
	}
}

int Channel::findUser(std::string nickName) {
	for (std::vector<std::pair<int, std::string> >::iterator it = users.begin(); it != users.end(); it++) {
		if (it->second == nickName) {
			return it->first; 
		}
	}
	return -1;
}

bool Channel::authenticateUser(int iKey) {
	return !keyFlag || key == iKey;
}

bool Channel::isFull() {
	if (limitFlag == true && users.size() >= ulimit) {
		return true;
	}
	return false;
}

bool Channel::getTopicFlag() {
	return this->topicFlag;
}
