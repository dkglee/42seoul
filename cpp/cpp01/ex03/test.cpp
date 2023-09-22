#include <iostream>
#include <string>

int main(void)
{
	std::string* str = new std::string("hello");

	std::cout << *str << std::endl;
	delete str;
}
