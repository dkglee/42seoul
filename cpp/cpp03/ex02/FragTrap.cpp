#include "FragTrap.hpp"

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
