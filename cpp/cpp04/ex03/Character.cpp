#include "Character.hpp"

const int Character::size = 4;

Character::Character(std::string n) {
	index = 0;
	for (int i = 0; i < 4; i++)
		flag[i] = false;
	name = n;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete parr[i];
	}
}

std::string const & Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	if (index == 4)
		return ;
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
	for (int i = 0; i < index; i++)
		parr[i] = o.parr[i]->clone();
	for (int i = 0; i < 4; i++)
		flag[i] = o.flag[i];
}

Character& Character::operator=(const Character& r) {
	index = r.index;
	name = r.name;
	for (int i = 0; i < index; i++)
		parr[i] = r.parr[i]->clone();
	for (int i = 0; i < 4; i++)
		flag[i] = r.flag[i];
	return *this;
}
