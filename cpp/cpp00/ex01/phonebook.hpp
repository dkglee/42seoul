#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

#include <string>

#include "contact.hpp"

class PhoneBook
{
private:
	Contact c[8];
	int head;
	PhoneBook(const PhoneBook&);
	PhoneBook& operator=(const PhoneBook&);
public:
	PhoneBook();
	void addContact();
	void searchContact();
	void exit();
	~PhoneBook();
};

#endif
