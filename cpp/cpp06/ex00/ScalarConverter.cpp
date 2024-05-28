#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str) {
	convertChar(str);
	convertInt(str);
	convertFloat(str);
	convertDouble(str);
}

void ScalarConverter::convertChar(std::string str) {
	int number = 0;
	int flag = 0;
	if (str.size() == 1 && !isdigit(str[0])) {
		flag = 1;
		number = static_cast<int>(str[0]);
	}
	try {
		double value = std::atof(str.c_str());
		if (std::isnan(value) || std::isinf(value)) {
			throw std::runtime_error("impossible");
		}
		if (flag != 1)
			number = static_cast<int>(value);
		if (number > 0 && number <= 255) {
			std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
		}
		else {
			throw std::runtime_error("non displayable");
		}
	}
	catch (std::exception& e) {
		std::cout << "char: " << e.what() << std::endl;
	}
}

void ScalarConverter::convertInt(std::string str) {
	int number = 0;
	int flag = 0;
	if (str.size() == 1 && !isdigit(str[0])) {
		flag = 1;
		number = static_cast<int>(str[0]);
	}
	try {
		double value = std::atof(str.c_str());
		if (std::isnan(value) || std::isinf(value)) {
			throw std::runtime_error("impossible");
		}
		if (flag != 1)
			number = static_cast<int>(value);
		std::cout << "int: " << static_cast<int>(number) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "int: " << e.what() << std::endl;
	}
	
}

void ScalarConverter::convertFloat(std::string str) {
	int number = 0;
	int flag = 0;
	if (str.size() == 1 && !isdigit(str[0])) {
		flag = 1;
		number = static_cast<int>(str[0]);
	}
	double value = std::atof(str.c_str());
	if (flag != 1)
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
}

void ScalarConverter::convertDouble(std::string str) {
	int number = 0;
	int flag = 0;
	if (str.size() == 1 && !isdigit(str[0])) {
		flag = 1;
		number = static_cast<int>(str[0]);
	}
	double value = std::atof(str.c_str());
	if (flag != 1)
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	else
		std::cout << "double: " << static_cast<double>(number) << std::endl;
}
