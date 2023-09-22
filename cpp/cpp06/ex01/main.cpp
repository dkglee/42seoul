#include <iostream>

struct Data {
	unsigned int x;
};

class Serializer {
public:
	static unsigned int* serialize(Data* ptr);
	static Data* deserialize(unsigned int* raw);
};

unsigned int* Serializer::serialize(Data* ptr) {
	void* ret = static_cast<void*>(ptr);
	return static_cast<unsigned int*>(ret);
}

Data* Serializer::deserialize(unsigned int* raw) {
	void* ret = static_cast<void*>(raw);
	return static_cast<Data*>(ret);
}

int main(void)
{
	Data d{15};

	Data* dptr = &d;
	std::cout << "dptr: " << dptr << std::endl;
	unsigned int* sePtr = Serializer::serialize(dptr);
	std::cout << "sePtr: " << sePtr << std::endl;
	std::cout << *sePtr << std::endl;
	Data* dePtr  = Serializer::deserialize(sePtr);
	std::cout << "dePtr: " << dePtr << std::endl;
	std::cout << dePtr->x << std::endl;
	return 0;
}
