#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
	unsigned int s_;
	T* arr_;
public:
	Array() : s_(0), arr_(NULL) {}
	Array(unsigned int n) : s_(n) {
		arr_ = new T[n];
	}
	Array(const Array& o) : s_(o.s_) {
		arr_ = new T[s_];
		for (unsigned int i = 0; i < s_; i++)
			arr_[i] = o.arr_[i];
	}
	Array& operator=(const Array& r) {
		s_ = r.s_;
		if (arr_)
			delete[] arr_;
		arr_ = new T[s_];
		for (unsigned int i = 0; i < s_; i++)
			arr_[i] = r.arr_[i];
		return *this;
	}
	T& operator[](int index) {
		if (index < 0 || index > (static_cast<int>(s_) - 1))
			throw std::exception();
		return arr_[index];
	}
	const T& operator[](int index) const {
		return const_cast<Array<T>&>(*this)[index];
	}
	unsigned int size() const {
		return s_;
	}
	~Array() {
		if (arr_)
			delete[] arr_;
	}
};

#endif
