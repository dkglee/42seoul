#include "MutanStack.hpp"

int main(void) {
	MutanStack<int> mstack;

	mstack.push(5);
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);
	mstack.push(9);

	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	MutanStack<int>::iterator it = mstack.begin();
	MutanStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}
