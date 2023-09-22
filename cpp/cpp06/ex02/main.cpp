#include <iostream>
#include <string>

class Base {
protected:
	std::string type;
public:
	Base(std::string n) : type(n) {}
	virtual const std::string getType() const {
		return type;
	}
	virtual ~Base() {}
};

class A : public Base {
public:
	A() : Base("A") {}
	virtual ~A() {}
};

class B : public Base {
public:
	B() : Base("B") {}
	virtual ~B() {}
};

class C : public Base {
public:
	C() : Base("C") {}
	virtual ~C() {}
};

Base* generate(void) {
	Base* ret = new A;
	return ret;
}

void identify(Base* p) {
	std::cout << p->getType();
}

void identify(Base& p) {
	std::cout << p.getType();

}

int main(void)
{
	Base* ptr = generate();

	identify(ptr);
	identify(*ptr);
	return 0;
}
