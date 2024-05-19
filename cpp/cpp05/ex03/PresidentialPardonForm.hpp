#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(std::string n = "Default");
	PresidentialPardonForm(const PresidentialPardonForm&);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
private:
	std::string target;
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
};

#endif
