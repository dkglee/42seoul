#include "static.hpp"

void Static::convertChar(std::string str) {
	std::cout << "char: ";
	if (str == "nan" || str == "-inf" || str == "+inf")
		std::cout << "impossible";
	else {
		int n = atoi(str.c_str());
		if (n == 0)
			std::cout << "Non displayable";
		else if (n < 0 || n > 255)
			std::cout << "impossible";
		else
			std::cout << '\'' << static_cast<char>(n) << '\'';
	}
	std::cout << std::endl;
}

void Static::convertInt(std::string str) {
	std::cout << "int: ";
	if (str == "nan" || str == "-inf" || str == "+inf")
		std::cout << "impossible";
	else {
		int n = atoi(str.c_str());
		std::cout << n;
	}
	std::cout << std::endl;
}

void Static::convertFloat(std::string str) {
	std::cout << "float: ";
	if (str == "nan" || str == "-inf" || str == "+inf")
		std::cout << str << 'f';
	else {
		double n = atof(str.c_str());
		std::cout << static_cast<float>(n) << 'f';
	}
	std::cout << std::endl;
}

void Static::convertDouble(std::string str) {
	std::cout << "double: ";
	if (str == "nan" || str == "-inf" || str == "+inf")
		std::cout << str;
	else {
		double n = atof(str.c_str());
		std::cout << n;
	}
	std::cout << std::endl;
}
