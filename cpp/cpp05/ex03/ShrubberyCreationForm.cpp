#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string n) : AForm(n, false, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() && this->getGradeExecute() >= executor.getGrade()) {
		std::string newFile = this->getName() + "_shrubbery";
		std::ofstream outputFile(newFile.c_str());
		if (!outputFile.is_open()) {
			std::cerr << "출력 파일을 열 수 없다." << std::endl;
			exit(-1);
		}
		outputFile << "\'|\'" << std::endl;
		outputFile.close();
		executor.executeForm(*this);
	} else {
		throw ShrubberyCreationForm::GradeTooLowException();
	}
}
