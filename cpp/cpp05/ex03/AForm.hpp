#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool signFlag;
	const int gradeSigned;
	const int gradeExecute;
	AForm& operator=(const AForm&);
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	AForm(std::string n, bool flag, int gS, int gE);
	AForm(const AForm&);
	virtual ~AForm();
	std::string getName() const;
	bool getSigned() const;
	int getGradeSigned() const;
	int getGradeExecute() const;
	void beSigned(const Bureaucrat&);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream&, AForm&);

#endif
