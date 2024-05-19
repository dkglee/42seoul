#include "Bureaucrat.hpp"

int main(void)
{
	try {
		// Bureaucrat errorCase("hello", 151);
		// Bureaucrat errorCase("hello", -1);

		Bureaucrat b("b", 150);
		std::cout << b << std::endl;
		// b.decrement();
		b.increment();
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
