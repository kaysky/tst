#include <iostream>

#pragma pack(1)

using namespace std;

class zero {};

class A
{
	int a;
public:
	A() {}
	virtual	~A() {}
};

class B
{
	char b;
public:
	B() {}
	virtual ~B() {}
	virtual char get() { return b; }
};

class C: virtual public B /*virtual +8 bayt*/
{

public:
	C() {}
	virtual ~C() {}

};

class D : virtual public B
{

public:
	D() {}
	virtual ~D() {}
};

class E : public C
	, public D
{};



int main(int argc, char *argv[])
{
	std::cout << "test size of obj" << std::endl;
	
	A a;
	std::cout << "zero size is :" << sizeof(zero) << std::endl;
	std::cout << "size of int is :" << sizeof(int) << std::endl;
	std::cout << "size of void* is :" << sizeof(void*) << std::endl;
	std::cout << "size of A is :" << sizeof(A) << std::endl;
	std::cout << "size of a is :" << sizeof(a) << std::endl;
	std::cout << "size of B is :" << sizeof(B) << std::endl;
	std::cout << "size of C is :" << sizeof(C) << std::endl;
	
	std::cout << "size of D is :" << sizeof(D) << std::endl;
	std::cout << "size of E is :" << sizeof(E) << std::endl;


	std::cout << "end of the test" << std::endl;
	return 0;
}
