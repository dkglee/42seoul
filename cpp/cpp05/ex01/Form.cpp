#include "Form.hpp"

Form::Form(std::string n, int gS, int gE) : name(n), signFlag(false), gradeSigned(gS), gradeExecute(gE) {
	if (gS < 1 || gE < 1)
		throw Form::GradeTooHighException();
	else if (gS > 150 || ge > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& c, Form& f) {
	std::cout << f.getName() << " should be over grade of " << f.getGradeSigned() << "to be signed, and it's now " << f.signFlag;
	return c;
}

std::string Form::getName() const {
	return name;
}

bool Form::getSigned() const {
	return signFlag;
}

const int Form::getGradeSigned() const {
	return gradeSigned;
}

const int Form::getGradeExecute() const {
	return gradeExecute;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() < this->getGradeSigned()) {
		signFlag = true;
		b.signForm(this->getName(), signFlag);
	} else {
		b.signForm(this->getName(), signFlag);
		throw Form::GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "grade is too low";
}

