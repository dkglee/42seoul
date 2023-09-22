#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
	std::string type;
public:
	Weapon& operator=(const Weapon&);
	Weapon();
	Weapon(std::string);
	Weapon(const Weapon&);
	~Weapon();
	const std::string& getType() const;
	void setType(std::string);
};

#endif
