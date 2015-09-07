#include <iostream>
#include <vector>
#include <memory>


using namespace std;


class base
{
public:
	base() {}
	virtual ~base() {}
	//static virtual void f1() {} // can't be static and virtual
	virtual void fun() = 0;
};

class A: public base
{
public:
	A() {}
	void fun() { std::cout << "A fun works" << std::endl;}
};

class B: public base
{
public:
	B() {}
	void fun() { std::cout << "B fun works" << std::endl;}
};

template<class T>
void call_fun(const T &obj)
{
	obj->fun();
}

template <class T>
class exemple
{
	T obj;
public:

	virtual void fun() { std::cout << "test virtual in template" << std::endl; }

};

class C: public exemple<int>
{
public:
	void fun() { std::cout << "C fun works" << std::endl; }
};

class D: public exemple<int>
{
public:
	void fun() { std::cout << "D fun works" << std::endl; }
};

int main(int argc, char *argv[])
{
	std::cout << "test templates and virtual functions" << std::endl;
	
	typedef unique_ptr<base> uptr;
	vector<uptr> vb;

	exemple<int> ex1;
	exemple<int> *ex;
	C c;
	D d;
	ex = &c;
	ex->fun();
	ex = &d;
	ex->fun();
	ex1.fun();

	vb.push_back( uptr(new A()));
	vb.push_back( uptr(new B())) ;

	for(const auto &i : vb)
	{
		i->fun();
	}

	call_fun(vb[0]);
	call_fun(vb[1]);

	std::cout << "end of the test." << std::endl;

	return 0;
}
