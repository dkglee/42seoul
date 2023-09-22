#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\n I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n I\'ve been coming for years whereas you started working here since last month." << std::endl;	
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::nocase(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	std::cout << std::endl;
}

const unsigned int Harl::hash(std::string str)
{
	unsigned int hash = 0;
	for (int i = 0; i < str.size(); i++)
		hash = 65599 * hash + str[i];
	return hash ^ (hash >> 16);
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlPtr)(void);

	HarlPtr parr[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::nocase};
	Harl obj;
	switch (hash(level))
	{
		case 3052675527:
			for (int i = 0; i < 4; i++)
				(obj.*parr[i])();
			break;
		case 1797274222:
			for (int i = 1; i < 4; i++)
				(obj.*parr[i])();
			break;
		case 2095463034:
			for (int i = 2; i < 4; i++)
				(obj.*parr[i])();
			break;
		case 1586814236:
			for (int i = 3; i < 4; i++)
				(obj.*parr[i])();
			break;
		default:
			(obj.*parr[4])();
			break;
	}
}
