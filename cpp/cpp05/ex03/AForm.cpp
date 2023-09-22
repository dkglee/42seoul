#include "AForm.hpp"

AForm::AForm(std::string n, bool flag, int gS, int gE) : name(n), signFlag(flag), gradeSigned(gS), gradeExecute(gE) {
	if (gS < 1 || gE < 1)
		throw AForm::GradeTooHighException();
	else if (gS > 150 || gE > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& c, AForm& f) {
	std::cout << f.getName() << " should be over grade of " << f.getGradeSigned() << "to be signed, and it's now " << f.signFlag;
	return c;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getSigned() const {
	return signFlag;
}

const int AForm::getGradeSigned() const {
	return gradeSigned;
}

const int AForm::getGradeExecute() const {
	return gradeExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() < this->getGradeSigned()) {
		signFlag = true;
		b.signForm(this->getName(), signFlag);
	} else {
		b.signForm(this->getName(), signFlag);
		throw AForm::GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "grade is too high";

}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "grade is too low";
}

