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

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->fnum = n << 8;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->fnum = static_cast<int>(roundf(f * (1 << fbits)));
}


float Fixed::toFloat(void) const {
	return (static_cast<float>(fnum) / static_cast<float>(1 << fbits));
}


int Fixed::toInt(void) const {
	int ret = static_cast<int>((*this).toFloat());
	return ret;
}

// std::ostream& operator<<(std::ostream& c, const Fixed& obj) {
// 	c << obj.toFloat();
// 	return c;
// }
