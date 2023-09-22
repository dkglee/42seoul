#include "Zombie.hpp"

int main(void)
{
	Zombie A("deulee");

	A.announce();

	Zombie* B = newZombie("Charlie");
	B->announce();
	delete B;

	randomChump("dim");
	return 0;
}
