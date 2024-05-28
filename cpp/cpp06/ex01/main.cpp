#include <iostream>
#include "Serializer.hpp"

int main() {
    Data myData;
	myData.id = 42;
	myData.value = 3.14;
    unsigned int* raw = Serializer::serialize(&myData);
    Data* pData = Serializer::deserialize(raw);

    std::cout << "Original ID: " << myData.id << ", Deserialized ID: " << pData->id << std::endl;
    std::cout << "Original Value: " << myData.value << ", Deserialized Value: " << pData->value << std::endl;

    return 0;
}
