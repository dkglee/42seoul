#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(std::string n = "Default");
	RobotomyRequestForm(const RobotomyRequestForm&);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
private:
	std::string target;
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
};

#endif
