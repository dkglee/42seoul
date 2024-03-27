#include "Harl.hpp"

int main(void)
{
	for (int i = 0; i < 10; i++) {
		std::string str;
		std::cin >> str;

		Harl obj;
		obj.complain(str);
	}
	return 0;
}
