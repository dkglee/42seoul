#include "Span.hpp"
#include <limits>

Span::Span() : size_(0) {
}

Span::Span(unsigned int n) : size_(n) {
}

Span::Span(const Span& n)
	: size_(n.size_), varr_(n.varr_.begin(), n.varr_.end())
{
}

Span& Span::operator=(const Span& n) {
	size_ = n.size_;
	varr_ = n.varr_;
	return *this;
}

Span::~Span() {}

Span::Exception::Exception(std::string n) : str(n) {}

const char* Span::Exception::what() const throw() {
	return str.c_str();
}

void Span::addNumber(int n) {
	if (varr_.size() >= size_)
		throw Exception("over bound");
	varr_.push_back(n);
}

long long Span::shortestSpan() {
	if (varr_.size() <= 1)
		throw Exception("not enough elements");
	std::sort(varr_.begin(), varr_.end());
	long long ret = std::numeric_limits<long long>::max();
	std::vector<int>::iterator it = varr_.begin() + 1;
	for (; it != varr_.end(); it++)
		ret = std::min(ret, static_cast<long long>(*it) - static_cast<long long>(*(it - 1)));
	return ret;
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	unsigned int n = std::distance(first, last);
	if (varr_.size() + n > size_)
		throw Exception("over bound");
	for (; first != last; first++)
		varr_.push_back(*first);
}

long long Span::longestSpan() {
	if (varr_.size() <= 1)
		throw Exception("not enough elements");
	std::sort(varr_.begin(), varr_.end());
	return static_cast<long long>(*(varr_.end() - 1) - *(varr_.begin()));
}

Span::Exception::~Exception() throw() {}
