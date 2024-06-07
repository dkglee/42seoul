#include "PmergeMe.hpp"
#include <limits>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>

void print_element(int i) {
	std::cout << i << " ";
}

int main(int argc, char* argv[])
{
	try {
		std::vector<int> numbers_vector;
		std::list<int> numbers_list;

		for (int i = 1; i < argc; i++) {
			long long num = std::atoll(argv[i]);
			if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
				throw std::invalid_argument("Error");
			}
			numbers_vector.push_back(num);
			numbers_list.push_back(num);
		}

		std::cout << "Before: ";
		std::for_each(numbers_vector.begin(), numbers_vector.end(), print_element);

		clock_t start_vector = clock();
		PmergeMe::MergeInsertSortVector(numbers_vector);
		clock_t end_vector = clock();

		clock_t start_list = clock();	
		PmergeMe::MergeInsertSortList(numbers_list);
		clock_t end_list = clock();

		std::cout << "\nAfter: ";
		std::for_each(numbers_vector.begin(), numbers_vector.end(), print_element);

		// for (auto it = numbers_vector.begin(); it != numbers_vector.end() - 1; it++) {
		// 	if (*it > *(it + 1)) {
		// 		std::cerr << "Error: vector not sorted" << std::endl;
		// 		return 1;
		// 	}
		// }

		// for (auto it = numbers_list.begin(); it != --numbers_list.end(); it++) {
		// 	if (*it > *(std::next(it))) {
		// 		std::cerr << "Error: list not sorted" << std::endl;
		// 		return 1;
		// 	}
		// }

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "\nVector time to process of " << numbers_vector.size() << " elements: " 
				<< static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC
				<< " us\n";
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "List time: to process of " << numbers_vector.size() << " elements: " 
				<< static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC
				<< " us\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
