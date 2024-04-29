#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* bptr;
public:
	Cat(std::string n = "Cat");
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	virtual ~Cat();
	virtual void makeSound() const;
};

#endif
