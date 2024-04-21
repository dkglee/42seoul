#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name", 100, 50, 30), ScavTrap("default_clap_name", 100, 50, 30), FragTrap("default_clap_name", 100, 50, 30), name("default") {
	std::cout << "Diamond constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	std::cout << "Diamond copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this == &other)
		return *this;
	std::cout << "Diamond assignation operator called" << std::endl;
	name = other.name;
	static_cast<ScavTrap&>(*this) = other;
	static_cast<FragTrap&>(*this) = other;
	return *this;
}

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
