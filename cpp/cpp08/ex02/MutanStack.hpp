#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template <typename T, typename Container = std::vector<T> >
class MutanStack {
private:
	std::stack<T, Container> sarr;
public:
	// struct iterator {
	// 	typedef random_access_iterator_tag iterator_category;
	// };
	typedef T* iterator;
	typedef const T* const_iterator;
	void push(T a) {
		sarr.push(a);
	}
	T pop() {
		return sarr.pop();
	}
	int size() {
		return sarr.size();
	}
	bool empty() {
		return sarr.empty();
	}
	T& top() {
		return sarr.top();
	}
	iterator end() {
		return &sarr.top() + 1;
	}
	iterator begin() {
		return end() - sarr.size();
	}
	const_iterator cend() {
		return end();
	}
	const_iterator cbegin() {
		return end() - sarr.size();
	}
};

#endif
