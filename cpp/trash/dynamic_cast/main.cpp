/* 
 *		Виртуальный механизм работает для ссылок и указателей
 *		если передать обьект по значению то произойдет 
 *		расщипление обьекта и ВМ не работает
 *		dynamic_cast<>() нужен для понижающего, повыщающего или side приведения типов
 *		в случае не правильного приведения типов для ссылок вызывает исключение
 *		для указателей возвращает 0ль 
 *
 *
 * */

#include <iostream>
#include <typeinfo>

using namespace std;

class base 
{
public:
	base() {}
	virtual ~base() {}

	virtual void fun() { std::cout << "base fun " << std::endl; }

};

class A: public base
{
public:
	A() {}
	~A() {}
	void fun() { std::cout << "A fun" << std::endl; }
};

class B: public base
{
public:
	B() {}
	~B() {}

	void fun() { std::cout << "B fun" << std::endl;  }
};

void call_fun(base& obj)
{
	obj.fun();
}

//void call_A(A obj)		//! произойдет расшипление и вызваны базовые ф-и
void call_A(A& obj)
{
	std::cout << "call_A:" << std::endl;
	obj.fun();
}

void call_B(B& obj)
{
	std::cout << "call_B:" << std::endl;
	obj.fun();
}


int main(int argc, char *argv[])
{
	std::cout << "test prj" << std::endl;
	try
	{
		A a;
		B b;
		// base& bb = a;	//! run_time error of bad_cast
		base& bb = b;
		call_fun(a);
		call_fun(b);

		call_A(a);
		call_B(dynamic_cast<B&>(bb));
		//call_B(bb);				//! error of inicialization
	}
	catch(std::bad_cast& ex)
	{
		std::cout << "exception:" << ex.what() << std::endl;
	}

	std::cout << "end of the test" << std::endl;
	return 0;
}
