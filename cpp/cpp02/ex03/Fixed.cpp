#include "Fixed.hpp"

const int Fixed::fbits = 8;

Fixed::Fixed() : fnum(0) {
}

Fixed::Fixed(const Fixed& o) : fnum(o.fnum) {
}

Fixed& Fixed::operator=(const Fixed& r) {
	fnum = r.getRawBits();
	return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
	return this->fnum;
}

void Fixed::setRawBits(int const raw) {
	this->fnum = raw;
}

Fixed::Fixed(const int n) {
	this->fnum = n << 8;
}

Fixed::Fixed(const float f) {
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
	Fixed ret = *this;
	++(*this);
	return ret;
}

Fixed& Fixed::operator--() {
	fnum -= 1;
	return *this;
}

const Fixed Fixed::operator--(int dummy) {
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
	ret.setRawBits((this->fnum * r.getRawBits()) >> fbits);
	return ret;
}

const Fixed Fixed::operator/(const Fixed& r) const {
	Fixed ret;
	int c = this->fnum << fbits;
	ret.setRawBits((c / r.getRawBits()));
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
