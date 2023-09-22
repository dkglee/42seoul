#include "MateriaSource.hpp"

const int MateriaSource::size = 4;

MateriaSource::MateriaSource() : index(0) {}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < index; i++)
		delete parr[i];
}

void MateriaSource::learnMateria(AMateria* ptr) {
	if (index == size)
		return ;
	parr[index++] = ptr;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < index; i++) {
		if (parr[i]->getType() == type) {
			return parr[i]->clone();
		}
	}
	std::cout << "Didn't learn that Materia: " << type << std::endl;
	return NULL;
}
