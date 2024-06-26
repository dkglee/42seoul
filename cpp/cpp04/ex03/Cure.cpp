#include "Cure.hpp"

Cure::Cure(std::string n) : AMateria(n) {}

Cure::~Cure() {}

Cure::Cure(const Cure& o) : AMateria(o) {}

Cure& Cure::operator=(const Cure& r) {
	if (this == &r)
		return *this;
	AMateria::operator=(r);
	return *this;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	AMateria* ret = new Cure();
	return ret;
}
