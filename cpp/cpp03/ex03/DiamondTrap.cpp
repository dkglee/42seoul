#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string n, int h, int e, int a) : ClapTrap(n + "_clap_name", h, e, a), ScavTrap(n + "_clap_name", h, e, a), FragTrap(n + "_clap_name", h, e, a), name(n) {
	std::cout << "Diamond constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << name << ' ' << this->getName() << std::endl;
}
