#include "Span.hpp"

Span::Span(unsigned int n) : index(0) {
	varr.resize(n);
}

Span::~Span() {}

Span::Exception::Exception(std::string n) : str(n) {}

const char* Span::Exception::what() const {
	return str.c_str();
}

void Span::addNumber(unsigned int n) {
	if (index >= varr.size())
		throw Exception("over bound");
	varr[index++] = n;
}

int Span::shortestSpan() {
	if (varr.size() <= 1)
		throw Exception("not enough elements");
	std::sort(varr.begin(), varr.end());
	int ret = 214748368;
	int i = 0;
	int j = 1;
	while (j < varr.size()) {
		ret = std::min(ret, varr[j++] - varr[i++]);
	}
	return ret;
}

void Span::addNumber(unsigned int n, std::vector<int>::iterator first, std::vector<int>::iterator last) {
	for (; first < last; first++) {
		*first = n;
	}
}

int Span::longestSpan() {
	if (varr.size() <= 1)
		throw Exception("not enough elements");
	std::sort(varr.begin(), varr.end());
	return varr[varr.size() - 1] - varr[0];
}

std::vector<int>::iterator Span::begin() {
	return varr.begin();
}

std::vector<int>::iterator Span::end() {
	return varr.end();
}
