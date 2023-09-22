#include "Dog.hpp"

Dog::Dog(std::string n) : Animal(n) {
	bptr = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog() {
	delete bptr;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog is barking" << std::endl;
}
