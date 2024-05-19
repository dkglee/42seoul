#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(std::string n = "Default");
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	virtual ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) const;
private:
	std::string target;
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
};

#endif
