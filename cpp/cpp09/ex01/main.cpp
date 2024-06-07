#include "RPN.hpp"
#include <exception>

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		std::stack<int> st;
		for (int i = 1; i < argc; i++) {
			RPN::rpn(st, argv[i]);
		}
		if (st.size() != 1)
			throw "Error";
		std::cout << st.top() << std::endl;
	}
	catch (const char* e) {
		std::cerr << e << std::endl;
	}
	return 0;
}
