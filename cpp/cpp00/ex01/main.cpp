#include "phonebook.hpp"
#include "contact.hpp"

int getNum(std::string str)
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
		std::cin >> temp;
		int ch = getNum(temp);
		if (ch == -1)
			std::cout << "Choose One of ADD, SEARCH, EXIT" << std::endl;
		else if (ch == 2) {
			(P.*parr[2])();
			break ;
		}
		else
			(P.*parr[ch])();
	}
	return 0;
}
