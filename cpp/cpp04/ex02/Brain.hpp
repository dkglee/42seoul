#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
	std::string arr[100];
	Brain(const Brain&);
	Brain& operator=(const Brain&);
public:
	Brain();
	~Brain();
};

#endif
