#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::vector<int>::iterator easyfind(T& a, int b) {
	return std::find(a.begin(), a.end(), b);
}

#endif
