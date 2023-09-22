#include "easyfind.hpp"

int main(void)
{
	std::vector<int> varr{1, 2, 3, 4, 5};

	std::vector<int>::iterator it = easyfind(varr, 3);
	std::cout << *it << std::endl;
	return 0;
}
