#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string n, int g) : name(n), grade(g) {
	if (g < 1)
		throw GradeTooHighException();
	else if (g > 150)
		throw GradeTooLowException();
}

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

void Bureaucrat::increaseGrade(int amount) {
	if (amount + grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade += amount;
}

void Bureaucrat::decreaseGrade(int amount) {
	if (grade - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade -= amount;
}

const char * Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too big";
}

const char * Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low";
}
