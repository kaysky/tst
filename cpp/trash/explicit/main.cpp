#include<iostream>

using namespace std;

class A 
{
	int a;
public:
	A() { std::cout << "A constructor" << std::endl; }
	~A() { std::cout << "A destructor" << std::endl; }
	A(int n) :a(n) { std::cout << "A cast constructor" << std::endl; }
	A(const A &a) :a(a.a) { std::cout << "A copy constructor" << std::endl; }
};

int main()
{
    cout << "test cast constructor: " << endl;

	A a = 10.0;		//explicit forbids use of expression like  a = 10 (a = A::A(10))

    std::cout << "end of the test." << std::endl;
    return 0;
}
