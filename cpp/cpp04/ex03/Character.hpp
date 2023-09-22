#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class ICharacter;

class Character : public ICharacter {
private:
	int index;
	static const int size;
	AMateria* parr[4];
	bool flag[4];
	std::string name;
public:
	Character(std::string);
	Character(const Character&);
	Character& operator=(const Character&);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
