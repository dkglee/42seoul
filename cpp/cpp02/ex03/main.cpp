#include "Point.hpp"

int main(void)
{
	Point a(0, 0), b(1, 2), c(2, 0);
	Point point(1, 1);

	if (bsp(a, b, c, point))
		std::cout << "it's inside the triangle" << std::endl;
	else
		std::cout << "it's not inside the triangle" << std::endl;
	return 0;
}
