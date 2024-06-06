#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span {
private:
	unsigned int size_;
	std::vector<int> varr_;
public:
	class Exception : public std::exception {
	private:
		std::string str;
	public:
		Exception(std::string);
		virtual ~Exception() throw();
		virtual const char* what() const throw();
	};
	Span();
	Span(unsigned int n);
	Span(const Span&);
	Span& operator=(const Span&);
	~Span();
	void addNumber(int);
	void addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
	long long shortestSpan();
	long long longestSpan();
};

#endif
