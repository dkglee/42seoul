#include "ScavTrap.hpp"

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
