#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
// #include <exception>

class Exception {
public:
	virtual ~Exception();
	virtual const char* what() const = 0;
};

class BadInputException : public Exception {
private:
	std::string err;
public:
	BadInputException(std::string _e);
	virtual ~BadInputException();
	virtual const char* what() const;
};

class NegativeIntException : public Exception {
public:
	virtual const char* what() const;
	virtual ~NegativeIntException();
};

class OverIntException : public Exception {
public:
	virtual const char* what() const;
	virtual ~OverIntException();
};

class ExchangeData {
private:
	std::map<std::string, float> mapping;
	ExchangeData(const ExchangeData&);
	ExchangeData& operator=(const ExchangeData&);
public:
	ExchangeData();
	class FailedOpenFileException : public Exception {
	public:
		virtual const char* what() const;
		virtual ~FailedOpenFileException();
	};
	void addValue(std::string line);
	void parseData();
	float findExchangeRate(std::string date);
	std::map<std::string, float>::iterator movingIter(int center);
	~ExchangeData();
};

std::string getDate(std::string line);
float getNum(std::string line);

#endif
