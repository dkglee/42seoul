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

void RPN::rpn(std::stack<int>& st, std::string exp) {
	int (*f[])(std::stack<int>&) = {&RPN::add, &RPN::sub, &RPN::pro, &RPN::div};
	try {
		for (size_t i = 0; i < exp.size(); i++) {
			int temp;
			if (exp[i] == '+')
				temp = f[0](st);
			else if (exp[i] == '-')
				temp = f[1](st);
			else if (exp[i] == '*')
				temp = f[2](st);
			else if (exp[i] == '/')
				temp = f[3](st);
			else if (exp[i] == ' ')
				continue;
			else if (exp[i] >= '0' && exp[i] <= '9')
				temp = exp[i] - '0';
			else
				throw "Error";
			st.push(temp);
		}
	}
	catch (const char* e) {
		throw e;
	}
}
