#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	ScavTrap();
	ScavTrap(const ScavTrap&);
	ScavTrap& operator=(const ScavTrap&);
public:
	ScavTrap(std::string n, int h = 100, int e = 50, int a = 20);
	~ScavTrap();
	void attack(const std::string&);
	void guardGate();
};

#endif
