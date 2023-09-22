#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(std::string n);
	virtual ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
