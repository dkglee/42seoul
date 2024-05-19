#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string n) : AForm("ShrubberyCreationForm", false, 145, 137), target(n) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other), target(other.target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() && this->getGradeExecute() >= executor.getGrade()) {
		std::string newFile = this->target + "_shrubbery";
		std::ofstream outputFile(newFile.c_str());
		if (!outputFile.is_open()) {
			std::cerr << "Unable to open file" << std::endl;
			return;
		}
		outputFile << "ASCII trees" << std::endl;
		outputFile.close();
	} else {
		throw ShrubberyCreationForm::GradeTooLowException();
	}
}
