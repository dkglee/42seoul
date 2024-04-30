#include "Character.hpp"

const int Character::size = 4;

Character::Character(std::string n) {
	index = 0;
	for (int i = 0; i < size; i++) {
		parr[i] = NULL;
		flag[i] = false;
	}
	name = n;
}

Character::~Character() {
	for (int i = 0; i < size; i++) {
		if (parr[i] != NULL)
			delete parr[i];
	}
}

std::string const & Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	if (index == size) {
		if (m != NULL)
			delete m;
		return ;
	}
	flag[index] = true;
	parr[index++] = m;

}

void Character::unequip(int idx) {
	flag[idx] = false;
}

void Character::use(int idx, ICharacter& target) {
	if (flag[idx] == false)
		return ;
	parr[idx]->use(target);
}

Character::Character(const Character& o) {
	index = o.index;
	name = o.name;
	for (int i = 0; i < size; i++) {
		if (o.parr[i] != NULL)
			parr[i] = o.parr[i]->clone();
		else
			parr[i] = NULL;
	}
	for (int i = 0; i < size; i++)
		flag[i] = o.flag[i];
}

Character& Character::operator=(const Character& r) {
	index = r.index;
	name = r.name;
	for (int i = 0; i < size; i++) {
		if (parr[i] != NULL)
			delete parr[i];
		if (r.parr[i] != NULL)
			parr[i] = r.parr[i]->clone();
		else
			parr[i] = NULL;
	}
	for (int i = 0; i < size; i++)
		flag[i] = r.flag[i];
	return *this;
}
