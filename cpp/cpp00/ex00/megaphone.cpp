#include <iostream>

namespace Deulee
{
	void printBig(const char* str)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				std::cout << static_cast<char>(str[i] - 32);
			else
				std::cout << static_cast<char>(str[i]);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			Deulee::printBig(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}
