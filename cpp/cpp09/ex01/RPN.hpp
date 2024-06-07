#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN {
public:
	static void rpn(std::stack<int>&, std::string);
private:
	RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	~RPN();
	
	static int add(std::stack<int>&);
	static int sub(std::stack<int>&);
	static int pro(std::stack<int>&);
	static int div(std::stack<int>&);
};

#endif
