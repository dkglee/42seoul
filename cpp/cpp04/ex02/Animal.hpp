#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
private:
	std::string type;
	Animal(const Animal&);
	Animal& operator=(const Animal&);
public:
	Animal(std::string n = "Animal");
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
