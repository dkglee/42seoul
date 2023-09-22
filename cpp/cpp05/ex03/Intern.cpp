#include "Intern.hpp"

unsigned int Intern::hash(std::string type) {
	unsigned int ret = 0;
	for (int i = 0; i < type.size(); i++) {
		ret += static_cast<unsigned int>(type[i]);
		ret %= 15555;
	}
	return ret;
}

AForm* Intern::makeForm(std::string type, std::string target) {
	unsigned int num = hash(type);
	AForm* ret;
	switch (num) {
		case 1700:
			ret = new RobotomyRequestForm(target);
			break;
		case 1867:
			ret = new ShrubberyCreationForm(target);
			break;
		case 1960:
			ret = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "there is no Form" << std::endl;
			break;
	}
	return ret;
}
