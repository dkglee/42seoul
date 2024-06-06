#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::vector<int>::iterator easyfind(T& a, int b) {
	std::vector<int>::iterator it = std::find(a.begin(), a.end(), b);
	if (it == a.end())
		throw std::exception();
	return it;
}

#endif
