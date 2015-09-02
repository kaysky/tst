/*
    Pure virtual function may have body but it isn't nessosary because
    pure virtual function must be defined in thair children 

*/

#include <iostream>

using namespace std;

class base
{

public:
	virtual ~base()=0;

	virtual void fun() =0;

};

base::~base()
{}

void base::fun()
{}

class A :public base
{
public:
	void fun() {}
};

int main(int argc, char *argv[])
{
	std::cout << "test pure virtualfunction" << std::endl;
	A a;
	std::cout << "end of the test" << std::endl;
	return 0;
}
