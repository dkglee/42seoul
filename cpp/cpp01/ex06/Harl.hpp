#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
	Harl(const Harl&);
	Harl& operator=(const Harl&);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void nocase(void);
	unsigned int hash(std::string);
public:
	Harl();
	~Harl();
	void complain(std::string);
};

#endif
