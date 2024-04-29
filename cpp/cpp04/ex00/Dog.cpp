#include "Dog.hpp"

Dog::Dog(std::string n) : Animal(n) {
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& o) : Animal(o) {
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& r) {
	std::cout << "Dog Assignation Operator called" << std::endl;
	if (this == &r)
		return *this;
	Animal::operator=(r);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog is barking" << std::endl;
}
