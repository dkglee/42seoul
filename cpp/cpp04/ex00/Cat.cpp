#include "Cat.hpp"

Cat::Cat(std::string n) : Animal(n) {
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat is crying" << std::endl;
}
