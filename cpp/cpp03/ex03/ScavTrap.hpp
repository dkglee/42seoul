#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
public:
	ScavTrap();
	ScavTrap(const ScavTrap&);
	ScavTrap& operator=(const ScavTrap&);
	ScavTrap(std::string n, int h = 100, int e = 50, int a = 20);
	~ScavTrap();
	void attack(const std::string&);
	void guardGate();
};

#endif
