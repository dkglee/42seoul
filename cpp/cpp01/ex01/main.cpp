#include "Zombie.hpp"

int main(void)
{
	Zombie* zb = zombieHorde(3, "deulee");
	for (int i = 0; i < 3; i++)
		zb[i].announce();
	delete[] zb;
	return 0;
}
