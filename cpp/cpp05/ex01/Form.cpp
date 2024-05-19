#include "Form.hpp"

Form::Form(std::string n, int gS, int gE) : name(n), signFlag(false), gradeSigned(gS), gradeExecute(gE) {
	if (gS < 1 || gE < 1)
		throw Form::GradeTooHighException();
	else if (gS > 150 || gE > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& f) : name(f.name), signFlag(f.signFlag), gradeSigned(f.gradeSigned), gradeExecute(f.gradeExecute) {}

Form::~Form() {}

std::ostream& operator<<(std::ostream& c, Form& f) {
	std::cout << f.getName() << " should be over grade of " << f.getGradeSigned() << "to be signed, and it's now " << f.getSigned() << std::endl;
	return c;
}

std::string Form::getName() const {
	return name;
}

bool Form::getSigned() const {
	return signFlag;
}

int Form::getGradeSigned() const {
	return gradeSigned;
}

int Form::getGradeExecute() const {
	return gradeExecute;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->getGradeSigned())
		throw Form::GradeTooLowException();
	signFlag = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

