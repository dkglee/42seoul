#include "RPN.hpp"

int RPN::add(std::stack<int>& s) {
	if (s.size() <= 1)
		throw "Error";
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();
	return a + b;
}

int RPN::sub(std::stack<int>& s) {
	if (s.size() <= 1)
		throw "Error";
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();
	return b - a;
}

int RPN::pro(std::stack<int>& s) {
	if (s.size() <= 1)
		throw "Error";
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();
	return a * b;
}

int RPN::div(std::stack<int>& s) {
	if (s.size() <= 1)
		throw "Error";
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();
	return b / a;
}
