#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	friend std::ostream& operator<<(std::ostream&, Bureaucrat&);
private:
	const std::string name;
	int grade;
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const noexcept;
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const noexcept;
	};
	Bureaucrat(std::string n, int g);
	~Bureaucrat();
	int getGrade() const throw();
	std::string getName() const throw();
	void increaseGrade(int);
	void decreaseGrade(int);
	void signForm(const std::string&, bool flag) const;
	void executeForm(AForm const & form) const;
};

#endif
