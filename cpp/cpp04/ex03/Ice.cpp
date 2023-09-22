#include "Ice.hpp"

Ice::Ice(std::string n) : AMateria(n) {}

Ice::~Ice() {}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	AMateria* ret = new Ice();
	return ret;
}
