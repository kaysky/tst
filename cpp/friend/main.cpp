#include <iostream>

using namespace std;

class A
{
	const int n = 10;

public:
	void fun() { std::cout << "A::fun()" << std::endl;  }
	friend void show(const A&);
};

void show(const A &a)
{
	std::cout << a.n << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "test prj" << std::endl;

	A a;
	a.fun();
	show(a);
	//a.show();	//ERROR show is not a memeber of class A!

	std::cout << "end of the test." << std::endl;
	return 0;
}
