#include <map>
#include <string>
#include <iostream>

class User {
private:
	std::string key;
public:
	User(std::string n) : key(n) {}
	std::string getString() {
		return key;
	}
};

int main(void) {
	User A("deulee");
	std::cout << A.getString() << std::endl;
	std::map<std::string, User> list;
	list.insert({"name", A});
	std::map<std::string, User>::iterator it = list.find("name");
	if (it != list.end()) {
		std::cout << it->second.getString() << std::endl;
	}
	return 0;
}
