#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	head = 0;
}

PhoneBook::~PhoneBook()
{}

void PhoneBook::addContact()
{
	typedef void (Contact::*ConArr)(std::string);
	
	ConArr arr[4] = {&Contact::setFirst, &Contact::setLast, &Contact::setNick, &Contact::setSec};
	std::cout << "Enter FirstName, LastName, NickName and DarkestSecret" << std::endl;
	std::string temp;
	for (int i = 0; i < 4; i++)
	{
		std::cin >> temp;
		(c[head % 8].*arr[i])(temp);
	}
	head += 1;
}

void PhoneBook::searchContact()
{
	typedef std::string (Contact::*pGet)();

	pGet parr[4] = {&Contact::getFirst, &Contact::getLast, &Contact::getNick, &Contact::getSec};
	int size = (head >= 8 ? 8 : head);
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout.width(10);
		std::cout << i + 1;
		for (int j = 0; j < 3; j++)
		{
			std::cout << '|';
			std::cout.width(10);
			std::string temp = (c[(head + i) % size].*parr[j])();
			if (temp.size() > 10) {
				std::cout << temp.substr(0, 9) << '.';
			}
			else {
				std::cout << temp;
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Press the index of the contact" << std::endl;
	while (size)
	{
		std::string ch;
		std::cin >> ch;
		if (ch.size() == 1 && ch[0] >= '1' && ch[0] <= size + '0')
		{
			for (int i = 0; i < 4; i++)
				std::cout << (c[(head + ch[0] - '0' - 1) % size].*parr[i])() << std::endl;
			break ;
		}
		else
			std::cout << "press again" << std::endl;
	}
}

void PhoneBook::exit()
{
	std::cout << "program is terminated" << std::endl;
}
