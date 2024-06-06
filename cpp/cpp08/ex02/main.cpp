#include "MutantStack.hpp"
#include <list>

int main(void) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);
	mstack.push(9);

	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "---------mstack----------" << std::endl;

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int> mstack2(mstack);
	MutantStack<int> mstack3;
	mstack3 = mstack;

	std::cout << "---------mstack2----------" << std::endl;

	it = mstack2.begin();
	ite = mstack2.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "---------mstack3----------" << std::endl;

	it = mstack3.begin();
	ite = mstack3.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "---------list----------" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_back(9);

	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;
	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();

	++it2;
	--it2;

	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
}
