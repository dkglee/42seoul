#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* ret;
	try {
		ret = new Zombie(name);
	}
	catch (std::bad_alloc& e) {
		std::cerr << "bad alloc: " << e.what() << std::endl;
	}
	return ret;
}
