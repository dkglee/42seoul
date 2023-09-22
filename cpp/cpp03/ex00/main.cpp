#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap deulee("deulee");
	ClapTrap dim("dim");

	deulee.attack("dim");
	dim.takeDamage(10);
	return 0;
}
