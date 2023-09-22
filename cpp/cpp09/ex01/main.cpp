#include "RPN.hpp"

int rpn(std::string exp) {
	std::stack<int> st;
	int (*f[])(std::stack<int>&) = {&RPN::add, &RPN::sub, &RPN::pro, &RPN::div};
	try {
		for (int i = 0; i < exp.size(); i++) {
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
				continue;
			st.push(temp);
		}
	}
	catch (const char* e) {
		throw e;
	}
	return st.top();
}

int main(int argc, char* argv[])
{
	try {
		std::cout << rpn(argv[1]) << std::endl;
	}
	catch (const char* e) {
		std::cerr << e << std::endl;
	}
}
