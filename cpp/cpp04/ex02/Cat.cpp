#include "Cat.hpp"

Cat::Cat(std::string n) : Animal(n) {
	bptr = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& o) : Animal(o) {
	bptr = new Brain(*o.bptr);
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& r) {
	if (this == &r)
		return *this;
	Animal::operator=(r);
	delete bptr;
	bptr = new Brain(*r.bptr);
	std::cout << "Cat Assignation Operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete bptr;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat is crying" << std::endl;
}
