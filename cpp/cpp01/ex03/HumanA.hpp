#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon& type;
	HumanA(const HumanA&);
	HumanA& operator=(const HumanA&);
public:
	HumanA(std::string, Weapon&);
	~HumanA();
	void attack() const;
};

#endif
