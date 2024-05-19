#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
	const std::string name;
	int grade;
	Bureaucrat& operator=(const Bureaucrat&);
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
	Bureaucrat(std::string n = "Default", int g = 150);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();
	int getGrade() const throw();
	std::string getName() const throw();
	void increment();
	void decrement();
};

std::ostream& operator<<(std::ostream&, Bureaucrat&);

#endif
