#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* type;
	HumanB(const HumanB&);
	HumanB& operator=(const HumanB&);
public:
	HumanB(std::string);
	~HumanB();
	void setWeapon(Weapon&);
	void attack() const;
};

#endif
