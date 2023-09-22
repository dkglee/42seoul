#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
		Bureaucrat b("hello", 5);
		Form c("Test A", 3);
		c.beSigned(b);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
