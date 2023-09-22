#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;
	Zombie(const Zombie& copy);
	Zombie& operator=(const Zombie& other);
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(std::string name);
	void announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif
