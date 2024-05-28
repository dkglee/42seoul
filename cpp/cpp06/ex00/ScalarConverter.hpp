#ifndef STATIC_HPP
# define STATIC_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter {
public:
	static void convert(std::string str);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
	static void convertChar(std::string str);
	static void convertInt(std::string str);
	static void convertFloat(std::string str);
	static void convertDouble(std::string str);
};

#endif
