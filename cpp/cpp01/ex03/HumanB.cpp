#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n)
{}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon& w)
{
	type = &w;
}

void HumanB::attack() const
{
	std::cout << name << " attacks with their " << type->getType() << std::endl;
}
