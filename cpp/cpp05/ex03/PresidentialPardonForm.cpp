#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string n) : AForm(n, false, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() && this->getGradeExecute() >= executor.getGrade()) {
		executor.executeForm(*this);
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} else {
		throw PresidentialPardonForm::GradeTooLowException();
	}
}
