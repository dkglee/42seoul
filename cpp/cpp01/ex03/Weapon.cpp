#include "Weapon.hpp"

Weapon::Weapon(std::string n) : type(n)
{
}

Weapon::Weapon(const Weapon& other) : type(other.type)
{
}

Weapon& Weapon::operator=(const Weapon& other)
{
	type = other.type;
	return *this;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string n)
{
	type = n;
}

const std::string& Weapon::getType() const
{
	return type;
}
