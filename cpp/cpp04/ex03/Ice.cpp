#include "Ice.hpp"

Ice::Ice(std::string n) : AMateria(n) {}

Ice::Ice(const Ice& o) : AMateria(o) {}

Ice& Ice::operator=(const Ice& r) {
	if (this == &r)
		return *this;
	AMateria::operator=(r);
	return *this;
}

Ice::~Ice() {}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	AMateria* ret = new Ice();
	return ret;
}
