#include "contact.hpp"

Contact::Contact()
{}

Contact::Contact(const Contact& c) : idx(c.idx), firstName(c.firstName), lastName(c.lastName), nickName(c.nickName), darkestSecret(c.darkestSecret)
{}

Contact::~Contact()
{}

void Contact::setFirst(std::string str)
{
	this->firstName = str;
}

void Contact::setLast(std::string str)
{
	this->lastName = str;
}

void Contact::setNick(std::string str)
{
	this->nickName = str;
}

void Contact::setSec(std::string str)
{
	this->darkestSecret = str;
}

void Contact::setIn(int num)
{
	this->idx = num;
}

std::string Contact::getFirst()
{
	return this->firstName;
}

std::string Contact::getLast()
{
	return this->lastName;
}

std::string Contact::getNick()
{
	return this->nickName;
}

std::string Contact::getSec()
{
	return this->darkestSecret;
}

