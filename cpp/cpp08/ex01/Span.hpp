#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span {
private:
	int index;
	std::vector<int> varr;
public:
	class Exception {
	private:
		std::string str;
	public:
		Exception(std::string);
		const char* what() const;
	};
	Span(unsigned int n);
	void addNumber(unsigned int);
	void addNumber(unsigned int, std::vector<int>::iterator, std::vector<int>::iterator);
	int shortestSpan();
	int longestSpan();
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
	~Span();
};

#endif
