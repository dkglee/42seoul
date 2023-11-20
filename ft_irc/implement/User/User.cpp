#include "../../header/User.hpp"

void User::setUser(std::string n) {
	this->u_name = n;
}

void User::setNick(std::string n) {
	this->n_name = n;
}

void User::setNewUser(bool flag, std::string u, std::string n) {
	this->setNick(n);
	this->setUser(u);
	this->op = flag;
	this->assocChannel = 0;
}

bool User::isOP() {
	return this->op;
}

std::string User::getNick() {
	return this->n_name;
}

void User::kicked() {
	this->assocChannel = 0;
}

int User::getChannel() {
	return this->assocChannel;
}

void User::setChannel(int n) {
	this->assocChannel = n;
}

void User::setOP() {
	op = ~op;
}
