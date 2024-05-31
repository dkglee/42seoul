#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void printElement(const T& a) {
	std::cout << a << ' ';
}

template <typename T, typename Func>
void iter(T* ptr, int size, Func f) {
	for (int i = 0; i < size; i++)
		f(*(ptr + i));
}

#endif
