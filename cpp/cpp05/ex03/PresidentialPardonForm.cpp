#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string n) : AForm("PresidentialPardonForm", false, 25, 5), target(n) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) : AForm(other), target(other.target) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned() || this->getGradeExecute() < executor.getGrade()) {
		throw PresidentialPardonForm::GradeTooLowException();
	}
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
