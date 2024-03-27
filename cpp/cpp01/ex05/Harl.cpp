#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;	
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::validate(std::string level)
{
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cerr << "Invalid level: " << level << std::endl;
		return 1;
	}
	return 0;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlPtr)(void);

	HarlPtr parr[26];

	parr['D' - 65] = &Harl::debug;
	parr['I' - 65] = &Harl::info;
	parr['W' - 65] = &Harl::warning;
	parr['E' - 65] = &Harl::error;

	Harl obj;
	if (!validate(level))
		(obj.*parr[level[0] - 65])();
}
