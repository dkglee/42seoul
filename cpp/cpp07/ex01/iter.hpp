#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void printElement(T& a) {
	std::cout << a << ' ';
}

template <typename T>
void iter(T* ptr, int size, void f(T&)) {
	for (int i = 0; i < size; i++)
		f(*(ptr + i));
}

#endif
