#include "AMateria.hpp"

AMateria::AMateria(std::string const & t) : type(t) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) {
	type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other) {
	type = other.type;
	return *this;
}

std::string const & AMateria::getType() const {
	return type;
}
