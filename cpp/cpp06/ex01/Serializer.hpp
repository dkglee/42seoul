#ifndef SERIALIZER_H
# define SERIALIZER_H

struct Data {
    int id;
    double value;
};

class Serializer {
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
public:
    static unsigned int* serialize(Data* ptr);
    static Data* deserialize(unsigned int* raw);
};

#endif
