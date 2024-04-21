#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoint(10), energyPoint(10), attackDamage(0) {
	std::cout << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) : name(c.name), hitPoint(c.hitPoint), energyPoint(c.energyPoint), attackDamage(c.attackDamage) {
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c) {
	if (this == &c)
		return *this;
	std::cout << "assignation operator called" << std::endl;
	name = c.name;
	hitPoint = c.hitPoint;
	energyPoint = c.energyPoint;
	attackDamage = c.attackDamage;
	return *this;
}

ClapTrap::ClapTrap(std::string n, int h, int e, int a) : name(n), hitPoint(h), energyPoint(e), attackDamage(a) {
	std::cout << "constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " get damaged of " << amount << std::endl;
	hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << name << " is repaired by itself amount of " << amount << std::endl;
	hitPoint += amount;
	energyPoint -= 1;
}

void ClapTrap::lossEnergy() {
	energyPoint -= 1;
}

int ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}

std::string ClapTrap::getName() const {
	return this->name;
}
