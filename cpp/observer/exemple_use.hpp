#ifndef __EXEMPLE__HH__

#define  __EXEMPLE__HH__

#include "observer.hpp"

using namespace kki;

namespace exemple
{

class A :public Observer
{
	public:
		A(int id) :Observer(id) {}
		void update()
		{
			std::cout << "A informed about event of subject" << std::endl;
		}
};

class B :public Observer
{
	public:
		B(int id) :Observer(id) {}
		void update()
		{
			std::cout << "B informed about event of subject" << std::endl;
		}
};

class C :public Observer
{
	public:
		C(int id) :Observer(id) {}
		void update()
		{
			std::cout << "C informed about event of subject" << std::endl;
		}
};

class timer :public Subject
{
};


};

#endif //__EXEMPLE__HH__
