#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
	Dog(const Dog&);
	Dog& operator=(const Dog&);
public:
	Dog(std::string n = "Dog");
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif
