#include "Cat.hpp"

Cat::Cat(std::string n) : Animal(n) {
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& o) : Animal(o) {
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& r) {
	std::cout << "Cat Assignation Operator called" << std::endl;
	if (this == &r)
		return *this;
	Animal::operator=(r);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat is crying" << std::endl;
}
