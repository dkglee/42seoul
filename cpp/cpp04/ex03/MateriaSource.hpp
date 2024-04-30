#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
	static const int size;
	int index;
	AMateria* parr[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource&);
	MateriaSource& operator=(const MateriaSource&);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
