#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default", 100, 50, 20) {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& s) : ClapTrap(s) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& s) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this == &s)
		return *this;
	ClapTrap::operator=(s);
	return *this;
}

FragTrap::FragTrap(std::string n, int h, int e, int a) : ClapTrap(n, h, e, a) {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->lossEnergy();
}

void FragTrap::highFiveGuys(void) {
	std::cout << "FragTrap " << this->getName() << " do highFivesGuys" << std::endl;
	this->lossEnergy();
}
