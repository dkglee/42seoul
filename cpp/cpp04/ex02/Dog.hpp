#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* bptr;
	Dog(const Dog&);
	Dog& operator=(const Dog&);
public:
	Dog(std::string n = "Dog");
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif
