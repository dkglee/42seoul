#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& o) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		arr[i] = o.arr[i];
}

Brain& Brain::operator=(const Brain& r) {
	std::cout << "Brain Assignation Operator called" << std::endl;
	if (this == &r)
		return *this;
	for (int i = 0; i < 100; i++)
		arr[i] = r.arr[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain	destructor called" << std::endl;
}
