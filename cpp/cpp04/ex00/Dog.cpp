#include "Dog.hpp"

Dog::Dog(std::string n) : Animal(n) {
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog is barking" << std::endl;
}
