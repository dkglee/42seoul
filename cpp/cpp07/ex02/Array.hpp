#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
	unsigned int s;
	T* arr;
public:
	Array() : s(0) {}
	Array(unsigned int n) : s(n) {
		arr = new T[n];
	}
	Array(const Array& o) : s(o.s) {
		arr = new T[s];
		for (int i = 0; i < s; i++)
			arr[i] = o.arr[i];
	}
	Array& operator=(const Array& r) {
		s = r.s;
		arr = new T[s];
		for (int i = 0; i < s; i++)
			arr[i] = r.arr[i];
	}
	T& operator[](int index) {
		if (index < 0 || index > s)
			throw std::exception();
		return arr[index];
	}
	const T& operator[](int index) const {
		return const_cast<Array *>(this)[index];
	}
	unsigned int size() {
		return s;
	}
	~Array() {
		delete[] arr;
	}
};

#endif
