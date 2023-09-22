#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string name;
	DiamondTrap();
	DiamondTrap(const DiamondTrap&);
	DiamondTrap& operator=(const DiamondTrap&);
public:
	DiamondTrap(std::string n, int h = 100, int e = 50, int a = 30);
	~DiamondTrap();
	void attack(const std::string&);
	void whoAmI();
};

#endif
