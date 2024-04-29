#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
public:
	Dog(std::string n = "Dog");
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif
