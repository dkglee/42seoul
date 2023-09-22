#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private:
	FragTrap();
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);
public:
	FragTrap(std::string n, int h = 100, int e = 100, int a = 30);
	~FragTrap();
	void attack(const std::string&);
	void highFiveGuys(void);
};

#endif
