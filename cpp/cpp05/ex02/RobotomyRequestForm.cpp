#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string n) : AForm("RobotomyRequestForm", false, 72, 45), target(n) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & o) : AForm(o), target(o.target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned() || this->getGradeExecute() < executor.getGrade()) {
		throw RobotomyRequestForm::GradeTooLowException();
	}
	std::srand(std::time(NULL));
	if (std::rand() & 2)
		std::cout << this->getName() << " has been robotomized successfully 50 percent of them" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}
