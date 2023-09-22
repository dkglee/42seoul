#include "Array.hpp"

int main(void)
{
	Array<int> iarr(5);

	for (int i = 0; i < 5; i++)
		iarr[i] = i + 1;
	
	for (int i = 0; i < 5; i++)
		std::cout << iarr[i] << ' ';
	std::cout << std::endl;
	return 0;
}
