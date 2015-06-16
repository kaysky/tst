#ifndef __A_LIB__HPP__

#define __A_LIB__HPP__

#include <iostream>
#include <string>

class baseA
{
	std::string aName;
public:
	baseA(std::string str)
		: aName(str)
	{}

	virtual ~baseA () {}
	virtual void mega_fun() = 0;

private:
	/* data */

protected:
	void set_name(std::string str) { aName = str; }
	std::string get_name() { return aName;  }
};

class A : public baseA
{
public:
	A(std::string str);
	~A();

	void mega_fun();
	void change_name(std::string str);
};

class B : public baseA
{
public:
	B (std::string str);
	~B ();
	void mega_fun();

private:
	/* data */
};

#endif // __A_LIB__HPP__
