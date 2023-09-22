#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
	Cat(const Cat&);
	Cat& operator=(const Cat&);
public:
	Cat(std::string n = "Cat");
	virtual ~Cat();
	virtual void makeSound() const;
};

#endif
