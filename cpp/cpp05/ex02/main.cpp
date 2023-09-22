#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try {
		ShrubberyCreationForm sf("grara");
		PresidentialPardonForm pf("trara");
		RobotomyRequestForm af("rroobbo");
		Bureaucrat a("deulee", 1);

		sf.beSigned(a);
		pf.beSigned(a);
		af.beSigned(a);
		sf.execute(a);
		pf.execute(a);
		af.execute(a);
	}
	catch (std::exception& e) {

	}
}
