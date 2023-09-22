#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string n) : AForm(n, false, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() && this->getGradeExecute() >= executor.getGrade()) {
		executor.executeForm(*this);
		std::cout << this->getName() << " has been robotomized successfully 50 percent of them" << std::endl;
	} else {
		std::cout << "the robotomy failed" << std::endl;
		throw RobotomyRequestForm::GradeTooLowException();
	}
}
