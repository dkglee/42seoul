#include "Span.hpp"

int main(void)
{
	try {
		std::vector<int> v;
		for (int i = 0; i < 100000; i++)
			v.push_back(i);

		Span sp1(10000);
		sp1.addNumber(v.begin(), v.begin() + 10000);
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
		std::cout << "-------------" << std::endl;

		Span sp2;
		sp2 = sp1;
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		std::cout << "-------------" << std::endl;
		Span sp3(sp1);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;

		std::cout << "-------------" << std::endl;
		Span sp4(10000);
		sp4.addNumber(v.begin() + 10000, v.begin() + 20000);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
		
		std::cout << "-------------" << std::endl;
		Span sp5 = Span(5);
		sp5.addNumber(6);
		sp5.addNumber(3);
		sp5.addNumber(17);
		sp5.addNumber(9);
		sp5.addNumber(11);
		std::cout << sp5.shortestSpan() << std::endl;
		std::cout << sp5.longestSpan() << std::endl;
		std::cout << "-------------" << std::endl;
		try {
			Span sp6 = Span(2);
			sp6.addNumber(1);
			sp6.addNumber(3);
			sp6.addNumber(5);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "-------------" << std::endl;
		try {
			Span sp7 = Span(2);
			sp7.addNumber(1);
			sp7.shortestSpan();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
