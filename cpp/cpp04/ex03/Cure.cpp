#include "Cure.hpp"

Cure::Cure(std::string n) : AMateria(n) {}

Cure::~Cure() {}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	AMateria* ret = new Cure();
	return ret;
}
