#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {(void)other;}

Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; }

Serializer::~Serializer() {}

unsigned int* Serializer::serialize(Data* ptr) {
    return reinterpret_cast<unsigned int*>(ptr);
}

Data* Serializer::deserialize(unsigned int* raw) {
    return reinterpret_cast<Data*>(raw);
}
