#include "Animal.hpp"

Animal::Animal(std::string n) : type(n) {
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal Class is making Sound" << std::endl;
}

std::string Animal::getType() const {
	return type;
}


