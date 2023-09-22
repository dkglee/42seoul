#include "Bureaucrat.hpp"

int main(void)
{
	try {
		// Bureaucrat errorCase("hello", 151);
		Bureaucrat errorCase("hello", -1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
