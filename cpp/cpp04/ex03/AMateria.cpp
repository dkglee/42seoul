#include "AMateria.hpp"

AMateria::AMateria(std::string const & t) : type(t) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return type;
}
