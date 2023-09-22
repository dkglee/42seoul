#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	friend std::ostream& operator<<(std::ostream&, AForm&);
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
	AForm(std::string n, bool flag, int gS, int gE);
	virtual ~AForm();
	std::string getName() const;
	bool getSigned() const;
	const int getGradeSigned() const;
	const int getGradeExecute() const;
	void beSigned(const Bureaucrat&);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

#endif
