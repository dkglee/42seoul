#include "Cat.hpp"

Cat::Cat(std::string n) : Animal(n) {
	bptr = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
	delete bptr;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat is crying" << std::endl;
}
