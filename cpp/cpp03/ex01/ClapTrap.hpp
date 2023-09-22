#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string name;
	int hitPoint;
	int energyPoint;
	int attackDamage;
	ClapTrap();
	ClapTrap(const ClapTrap&);
	ClapTrap& operator=(const ClapTrap&);
public:
	ClapTrap(std::string n, int h = 10, int e = 10, int a = 0);
	~ClapTrap();
	void attack(const std::string&);
	void takeDamage(unsigned int);
	void beRepaired(unsigned int);
	void lossEnergy();
	int getAttackDamage() const;
	std::string getName() const;
};

#endif
