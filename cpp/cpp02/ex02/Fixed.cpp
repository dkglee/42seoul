#include "Fixed.hpp"

const int Fixed::fbits = 8;

Fixed::Fixed() : fnum(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& o) : fnum(o.fnum) {
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& r) {
	// std::cout << "Copy assignment operator called" << std::endl;
	fnum = r.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->fnum;
}

void Fixed::setRawBits(int const raw) {
	this->fnum = raw;
}

Fixed::Fixed(const int n) {
	// std::cout << "Int constructor called" << std::endl;
	this->fnum = n << 8;
}

Fixed::Fixed(const float f) {
	// std::cout << "Float constructor called" << std::endl;
	this->fnum = (int)(roundf(f * (1 << fbits)));
}


float Fixed::toFloat(void) const {
	return ((float)fnum / (float)(1 << fbits));
}

int Fixed::toInt(void) const {
	int ret = (*this).toFloat();
	return ret;
}

std::ostream& operator<<(std::ostream& c, const Fixed& obj) {
	c << obj.toFloat();
	return c;
}

bool Fixed::operator==(const Fixed& r) const {
	return this->fnum == r.getRawBits();
}

bool Fixed::operator!=(const Fixed& r) const {
	return !(*this == r);
}

bool Fixed::operator>(const Fixed& r) const {
	return this->fnum > r.getRawBits();
}

bool Fixed::operator>=(const Fixed& r) const {
	return (*this == r || *this > r);
}

bool Fixed::operator<(const Fixed& r) const {
	return !(*this >= r);
}

bool Fixed::operator<=(const Fixed& r) const {
	return !(*this > r);
}

Fixed& Fixed::operator++() {
	fnum += 1;
	return *this;
}

const Fixed Fixed::operator++(int dummy) {
	static_cast<void>(dummy);
	Fixed ret = *this;
	++(*this);
	return ret;
}

Fixed& Fixed::operator--() {
	fnum -= 1;
	return *this;
}

const Fixed Fixed::operator--(int dummy) {
	static_cast<void>(dummy);
	Fixed ret = *this;
	--(*this);
	return ret;
}

const Fixed Fixed::operator+(const Fixed& r) const {
	Fixed ret;
	ret.setRawBits(this->fnum + r.getRawBits());
	return ret;
}

const Fixed Fixed::operator-(const Fixed& r) const {
	Fixed ret;
	ret.setRawBits(this->fnum - r.getRawBits());
	return ret;
}

const Fixed Fixed::operator*(const Fixed& r) const {
	Fixed ret;
	ret.setRawBits(static_cast<int>(
		(static_cast<long long>(this->fnum)
		* static_cast<long long>(r.getRawBits()))
		>> fbits)
		);
	return ret;
}

const Fixed Fixed::operator/(const Fixed& r) const {
	Fixed ret;
	long long c = static_cast<long long>(this->fnum) << fbits;
	ret.setRawBits(static_cast<int>(
		(c / static_cast<long long>(r.getRawBits())))
		);
	return ret;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}
