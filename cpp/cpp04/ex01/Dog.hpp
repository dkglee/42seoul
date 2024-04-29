#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* bptr;
public:
	Dog(std::string n = "Dog");
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif
