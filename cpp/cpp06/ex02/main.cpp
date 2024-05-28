#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void) {
    srand(time(NULL));
    switch (rand() % 3) {
    case 0: return new A();
    case 1: return new B();
    case 2: return new C();
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception&) {
            std::cout << "C" << std::endl;
        }
    }
}

int main(void) {
	Base* p = generate();
	identify(p);
	identify(*p);
	return 0;
}
