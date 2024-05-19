#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string n, int g) : name(n), grade(g) {
	if (g < 1)
		throw GradeTooHighException();
	else if (g > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.getName()), grade(b.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() const throw() {
	return grade;
}

std::string Bureaucrat::getName() const throw() {
	return name;
}

std::ostream& operator<<(std::ostream& c, Bureaucrat& b) {
	c << b.getName() << ", bureaucrat grade " << b.getGrade();
	return c;
}

void Bureaucrat::increment() {
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade -= 1;
}

void Bureaucrat::decrement() {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade += 1;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too big";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
