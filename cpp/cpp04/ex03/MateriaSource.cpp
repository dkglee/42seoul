#include "MateriaSource.hpp"

const int MateriaSource::size = 4;

MateriaSource::MateriaSource() : index(0) {
	for (int i = 0; i < size; i++)
		parr[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < size; i++) {
		if (other.parr[i] != NULL) {
			parr[i] = other.parr[i]->clone();
		} else {
			parr[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < size; i++) {
		if (parr[i] != NULL)
			delete parr[i];
		if (other.parr[i] != NULL) {
			parr[i] = other.parr[i]->clone();
		} else {
			parr[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < size; i++) {
		if (parr[i] != NULL)
			delete parr[i];
	}
}

void MateriaSource::learnMateria(AMateria* ptr) {
	if (index == size) {
		if (ptr != NULL)
			delete ptr;
		return ;
	}
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
