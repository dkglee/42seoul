#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	friend std::ostream& operator<<(std::ostream&, Form&);
private:
	const std::string name;
	bool signFlag;
	const int gradeSigned;
	const int gradeExecute;
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const noexcept;
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const noexcept;
	};
	Form(std::string n, int gS, int gE);
	~Form();
	std::string getName() const;
	bool getSigned() const;
	const int getGradeSigned() const;
	const int getGradeExecute() const;
	void beSigned(const Bureaucrat&);
};

#endif
