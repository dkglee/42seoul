#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
private:
	int idx;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;
	Contact& operator=(const Contact&);
public:
	Contact();
	Contact(const Contact& copy);
	void setFirst(std::string str);
	void setLast(std::string str);
	void setNick(std::string str);
	void setSec(std::string str);
	void setIn(int num);
	std::string getFirst();
	std::string getLast();
	std::string getNick();
	std::string getSec();

	~Contact();
};

#endif
