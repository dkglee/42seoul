#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Intern someRandomIntern;
        AForm* form;

        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form) {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("presidential pardon", "Alice");
        if (form) {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("unknown form", "Target"); // 예외 발생
        if (form) {
            delete form;
        }

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
