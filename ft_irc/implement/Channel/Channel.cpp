#include "../../header/Channel.hpp"

void Channel::addUser(int socket, std::string user) {
	this->users.push_back({socket, user});
}

void Channel::removeUser(std::string user) {
	for (std::vector<std::pair<int, std::string> >::iterator it = this->users.begin(); it != this->users.end(); it++) {
		if (it->second == user) {
			this->users.erase(it);
			break;
		}
	}
}

void Channel::setTopic(std::string topic) {
	this->topic = topic;
}

std::vector<int> Channel::getUserSocketList() {
	std::vector<int> ret(users.size());
	std::vector<std::pair<int, std::string> >::iterator own = users.begin();
	for (std::vector<int>::iterator it = ret.begin(); it != ret.end(); it++) {
		*it = own->first;
	}
	return ret;
}
