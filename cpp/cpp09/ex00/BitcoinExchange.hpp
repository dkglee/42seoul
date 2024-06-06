#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	void loadPriceData();
	void processTransaction(const std::string& filename);
private:
	double getClosetPrice(const std::string& date);
	void ValidateDate(const std::string& date);
	void ValidateValue(double value);

	std::map<std::string, double> priceData_;
};
