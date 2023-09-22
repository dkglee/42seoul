#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(2, sp.begin(), sp.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
