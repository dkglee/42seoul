#include "Zombie.hpp"

Zombie::Zombie() {}

void Zombie::setName(std::string n)
{
	this->name = n;
}

Zombie::Zombie(std::string _n) : name(_n)
{}

Zombie::~Zombie()
{
	std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
