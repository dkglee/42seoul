#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon& w) : name(n), type(w)
{}

HumanA::~HumanA()
{}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << type.getType() << std::endl;
}
