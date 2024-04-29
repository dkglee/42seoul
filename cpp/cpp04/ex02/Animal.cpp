#include "Animal.hpp"

Animal::Animal(std::string n) : type(n) {
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor Called" << std::endl;
}

Animal::Animal(const Animal& o) : type(o.type) {
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal& Animal::operator=(const Animal& r) {
	std::cout << "Animal Assignation Operator Called" << std::endl;
	if (this == &r)
		return *this;
	type = r.type;
	return *this;
}

// void Animal::makeSound() const {
// 	std::cout << "Animal Class is making Sound" << std::endl;
// }

std::string Animal::getType() const {
	return type;
}


