#include "BitcoinExchange.hpp"

ExchangeData::~ExchangeData() {}

void ExchangeData::parseData() {
	std::ifstream inputFile("data.csv");
	if (!inputFile.is_open()) {
		std::cerr << "입력 파일을 열 수 없다." <<  std::endl;
		exit(-1);
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		addValue(line);
	}
	inputFile.close();
}

void ExchangeData::addValue(std::string line) {
	if (line == "date, exchange_rate")
		return ;
	std::string date(line.begin(), line.begin() + 10);
	std::string rate(line.begin() + 12, line.end());
	float exRate = atof(rate.c_str());
	mapping.insert({date, exRate});
}

std::map<std::string, float>::iterator ExchangeData::movingIter(int center) {
	std::map<std::string, float>::iterator ret = mapping.begin();
	for (int i = 0; i < center; i++)
		ret++;
	return ret;
}

float ExchangeData::findExchangeRate(std::string date) {
	std::map<std::string, float>::iterator begin = mapping.begin();
	int lo = 0;
	int hi = mapping.size();
	int center = (lo + hi) / 2;
	while (lo + 1 < hi) {
		if ((movingIter(center))->first <= date) {
			lo = center;
		}
		else {
			hi = center;
		}
		center = (lo + hi) / 2;
	}
	return (movingIter(lo))->second;
}

Exception::~Exception() {}

BadInputException::~BadInputException() {}

OverIntException::~OverIntException() {}

ExchangeData::FailedOpenFileException::~FailedOpenFileException() {}

NegativeIntException::~NegativeIntException() {}

const char* OverIntException::what() const {
	return "Error: too large a number";
}

const char* ExchangeData::FailedOpenFileException::what() const {
	return "Error: could not open file.";
}

const char* NegativeIntException::what() const {
	return "Error: not a positive number.";
}

const char* BadInputException::what() const {
	std::cerr << "Error: bad input => " << err;
	return "";
}

BadInputException::BadInputException(std::string _e) : err(_e) {}

std::string getDate(std::string line) {
	std::string ret = "";

	int i = 0;
	for (; line[i] != '-' && i < line.size() ; i++) {}
	std::string year(line.begin(), line.begin() + i);
	int j = i + 1;
	for (; line[j] != '-' && j < line.size() ; j++) {}
	std::string month(line.begin() + i + 1, line.begin() + j);
	if (atoi(month.c_str()) > 12)
		throw BadInputException(line);
	int l = j + 1;
	for (; line[l] != ' ' && l < line.size() ; l++) {}
	if (l >= line.size())
		throw BadInputException(line);
	std::string day(line.begin() + j + 1, line.begin() + l);
	if (atoi(day.c_str()) > 31)
		throw BadInputException(line);
	return ret + year + "-" + month + "-" + day;
}

float getNum(std::string line) {
	int i = 0;
	for (; line[i] != '|'; i++) {}
	std::string temp(line.begin() + i + 2, line.end());
	int num = atoi(temp.c_str());
	if (num < 0)
		throw NegativeIntException();
	if (num > 1000)
		throw OverIntException();
	return num;
}

ExchangeData::ExchangeData() {}
