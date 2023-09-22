#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN {
public:
	static int add(std::stack<int>&);
	static int sub(std::stack<int>&);
	static int pro(std::stack<int>&);
	static int div(std::stack<int>&);
};

#endif
