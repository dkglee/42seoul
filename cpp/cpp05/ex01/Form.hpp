#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
	const std::string name;
	bool signFlag;
	const int gradeSigned;
	const int gradeExecute;
	Form& operator=(const Form&);
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	Form(std::string n, int gS, int gE);
	Form(const Form&);
	~Form();
	std::string getName() const;
	bool getSigned() const;
	int getGradeSigned() const;
	int getGradeExecute() const;
	void beSigned(const Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, Form&);

#endif
