#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string type;
public:
	Animal(std::string n = "Animal");
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
