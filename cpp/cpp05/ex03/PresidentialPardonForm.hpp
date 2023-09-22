#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(std::string n);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
