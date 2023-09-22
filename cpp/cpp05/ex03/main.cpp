#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try {
		Intern random;
		AForm* rrf;

		rrf = random.makeForm("robotomy request", "Bender");
		Bureaucrat a("deulee", 1);
		rrf->beSigned(a);
		rrf->execute(a);
		delete rrf;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
