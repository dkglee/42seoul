#include "phonebook.hpp"
#include "contact.hpp"

int getIndex(std::string str)
{
	if (str == "ADD")
		return 0;
	else if (str == "SEARCH")
		return 1;
	else if (str == "EXIT")
		return 2;
	else
		return -1;
}

int main(void)
{
	PhoneBook P;
	typedef void (PhoneBook::*pPhone)();

	pPhone parr[3] = {&PhoneBook::addContact, &PhoneBook::searchContact, &PhoneBook::exit};
	std::string temp;
	while (1)
	{
		std::cout << "Choose ADD, SEARCH or EXIT" << std::endl;
		std::cin >> temp;
		int ch = getIndex(temp);
		if (ch == -1)
			continue ;
		else if (ch == 2) {
			(P.*parr[2])();
			break ;
		}
		else
			(P.*parr[ch])();
	}
	return 0;
}
