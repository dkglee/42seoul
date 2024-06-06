#include "easyfind.hpp"

int main(void)
{
	std::vector<int> varr;
	varr.push_back(1);
	varr.push_back(2);
	varr.push_back(3);
	varr.push_back(4);
	varr.push_back(5);

	try {
		std::vector<int>::iterator it = easyfind(varr, 6);
		std::cout << *it << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
