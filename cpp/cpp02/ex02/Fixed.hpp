#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	friend std::ostream& operator<<(std::ostream&, const Fixed&);
private:
	int fnum;
	static const int fbits;
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	bool operator==(const Fixed&) const;
	bool operator!=(const Fixed&) const;
	bool operator<(const Fixed&) const;
	bool operator<=(const Fixed&) const;
	bool operator>(const Fixed&) const;
	bool operator>=(const Fixed&) const;
	const Fixed operator+(const Fixed&) const;
	const Fixed operator-(const Fixed&) const;
	const Fixed operator*(const Fixed&) const;
	const Fixed operator/(const Fixed&) const;
	Fixed& operator++();
	const Fixed operator++(int);
	Fixed& operator--();
	const Fixed operator--(int);
	static Fixed& min(Fixed&, Fixed&);
	static const Fixed& min(const Fixed&, const Fixed&);
	static Fixed& max(Fixed&, Fixed&);
	static const Fixed& max(const Fixed&, const Fixed&);
};

#endif
