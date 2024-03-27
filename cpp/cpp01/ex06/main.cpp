#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2 && std::string(argv[1]).size() > 0)
	{
		Harl obj;
		obj.complain(std::string(argv[1]));
	}
	return 0;
}
