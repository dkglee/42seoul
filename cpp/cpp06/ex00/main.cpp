#include "static.hpp"

int main(int argc, char* argv[])
{
	Static c;

	c.convertChar(argv[1]);
	c.convertInt(argv[1]);
	c.convertFloat(argv[1]);
	c.convertDouble(argv[1]);
	return 0;
}
