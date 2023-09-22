#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* bptr;
	Cat(const Cat&);
	Cat& operator=(const Cat&);
public:
	Cat(std::string n = "Cat");
	virtual ~Cat();
	virtual void makeSound() const;
};

#endif
