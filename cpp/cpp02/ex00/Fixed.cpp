#include "Fixed.hpp"

const int Fixed::fbits = 8;

Fixed::Fixed() : fnum(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& o) : fnum(o.fnum) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& r) {
	std::cout << "Copy assignment operator called" << std::endl;
	fnum = r.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fnum;
}

void Fixed::setRawBits(int const raw) {
	this->fnum = raw;
}
