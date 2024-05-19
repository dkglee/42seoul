#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
        delete forms[i]; // 메모리 누수 방지
    }
    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form requested";
}
