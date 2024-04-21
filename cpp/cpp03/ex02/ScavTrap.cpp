#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) {
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this == &s)
		return *this;
	ClapTrap::operator=(s);
	return *this;
}

ScavTrap::ScavTrap(std::string n, int h, int e, int a) : ClapTrap(n, h, e, a) {
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->lossEnergy();
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode!" << std::endl;
	this->lossEnergy();
}
