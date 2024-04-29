#include "Dog.hpp"

Dog::Dog(std::string n) : Animal(n) {
	bptr = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& o) : Animal(o) {
	bptr = new Brain(*o.bptr);
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& r) {
	if (this == &r)
		return *this;
	Animal::operator=(r);
	delete bptr;
	bptr = new Brain(*r.bptr);
	std::cout << "Dog Assignation Operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete bptr;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog is barking" << std::endl;
}
