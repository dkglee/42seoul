#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	try {
		if (argc < 2)
			throw std::string("could not open file.");
		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open())
			throw std::string("could not open file.");
		ExchangeData dataBase;
		dataBase.parseData();
		std::string line;
		while (std::getline(inputFile, line)) {
			try {
				std::string date = getDate(line);
				float num = getNum(line);
				float rate = dataBase.findExchangeRate(date);
				std::cout << date << " => " << num << " = " << num * rate << std::endl;
			}
			catch (Exception& e) {
				std::cerr << e.what() << std::endl;
				inputFile.close();
			}
		}
		inputFile.close();
	}
	catch (std::string& e) {
		std::cerr << "Error: " << e << std::endl;
		inputFile.close();
	}
	return 0;
}
