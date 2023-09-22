#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

// class AMateria;

class Ice : public AMateria {
public:
	Ice(std::string n = "ice");
	virtual ~Ice();
	virtual void use(ICharacter&);
	virtual AMateria* clone() const;
};

#endif
