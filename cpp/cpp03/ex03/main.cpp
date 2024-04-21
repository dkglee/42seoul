#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap deulee("deulee");

	DiamondTrap deulee2(deulee);
	deulee2.whoAmI();

	deulee2 = deulee;
	deulee2.whoAmI();
	

	deulee.attack("dim");
	deulee.whoAmI();

	return 0;
}
