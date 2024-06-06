#include "BitcoinExchange.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	priceData_ = other.priceData_;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this == &other) {
		return *this;
	}
	priceData_ = other.priceData_;
	return *this;
}

void BitcoinExchange::loadPriceData() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open file : data.csv");
	}

	std::string line, date;
	double price;

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		if (date == "date") {
			continue;
		}
		try {
			ValidateDate(date);
			ss >> price;
			priceData_[date] = price;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
}

void BitcoinExchange::processTransaction(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open file : " + filename);
	}

	std::string line, date;
	double value;

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		ss >> value;
		
		if (date == "date ") {
			continue;
		}

		try {
			ValidateDate(date);
			ValidateValue(value);
			double price = getClosetPrice(date);
			std::cout << date << "=> " << value << " = " << (value * price) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

double BitcoinExchange::getClosetPrice(const std::string& date) {
	std::map<std::string, double>::iterator it = priceData_.lower_bound(date);
	if (it == priceData_.end() || it->first != date) {
		if (it == priceData_.begin()) {
			throw std::runtime_error("Error: date out of range. => " + date);
		}
		--it;
	}
	return it->second;
}

void BitcoinExchange::ValidateDate(const std::string& date) {
	int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	std::istringstream ss(date);
	int year, month, day;
	char c1, c2;
	ss >> year >> c1 >> month >> c2 >> day;
	if (c1 != '-' || c2 != '-') {
		throw std::runtime_error("Error: bad input => " + date);
	}
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		daysInMonth[1] = 29;
	}
	if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1]) {
		throw std::runtime_error("Error: bad input => " + date);
	}
}

void BitcoinExchange::ValidateValue(double value) {
	if (value < 0) {
		throw std::runtime_error("Error: not a positive number.");
	}
	if (value > 1000) {
		throw std::runtime_error("Error: too large a number.");
	}
}
