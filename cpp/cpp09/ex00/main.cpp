#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./bitcoin_exchange [filename]" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	try {
		exchange.loadPriceData();
		exchange.processTransaction(argv[1]);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
