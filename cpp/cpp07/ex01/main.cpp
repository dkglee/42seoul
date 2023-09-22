#include "iter.hpp"

int main(void)
{
	int iarr[5] = {0, 1, 2, 3, 4};
	double darr[6] = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7};

	iter(iarr, 5, printElement);
	std::cout << std::endl;
	iter(darr, 6, printElement);
	return 0;
}
