#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie inst(name);

	inst.announce();
}
