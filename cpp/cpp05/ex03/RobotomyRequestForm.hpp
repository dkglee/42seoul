#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(std::string n);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
