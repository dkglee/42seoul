#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

// class AMateria;

class Cure : public AMateria {
public:
	Cure(std::string n = "cure");
	virtual ~Cure();
	virtual void use(ICharacter&);
	virtual AMateria* clone() const;
};

#endif
