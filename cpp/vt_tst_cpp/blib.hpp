#ifndef __B_LIB__HPP__

#define __B_LIB__HPP__

#include "alib.hpp"
#include <iostream>
#include <string>

//class baseB
//{
//	std::string aName;
//public:
//	baseB(std::string str)
//		: aName(str)
//	{}
//
//	virtual ~baseB () {}
//	virtual void mega_fun() = 0;
//
//private:
//	/* data */
//
//protected:
//	void set_name(std::string str) { aName = str; }
//	std::string get_name() { return aName;  }
//};

class C : public baseA
{
public:
	C(std::string str);
	~C();
	void mega_fun();
};

class D : public baseA
{
public:
	D(std::string str);

	~D ();

	void mega_fun();

private:
	/* data */
};

#endif // __B_LIB__HPP__
