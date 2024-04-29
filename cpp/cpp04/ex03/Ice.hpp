#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

// class AMateria;

class Ice : public AMateria {
public:
	Ice(std::string n = "ice");
	Ice(const Ice& o);
	Ice& operator=(const Ice& r);
	virtual ~Ice();
	virtual void use(ICharacter&);
	virtual AMateria* clone() const;
};

#endif
