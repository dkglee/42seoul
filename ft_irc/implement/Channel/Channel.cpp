#include "../../header/Channel.hpp"

void Channel::addUser(std::string user) {
	this->users.push_back(user);
}

void Channel::removeUser(std::string user) {
	for (std::vector<std::string>::iterator it = this->users.begin(); it != this->users.end(); it++) {
		if (*it == user) {
			this->users.erase(it);
			break;
		}
	}
}
