#include "alib.hpp"


A::A(std::string str)
	: baseA(str)
{}

A::~A()
{}

void A::mega_fun()
{
	std::cout << "object name is:" << get_name() << std::endl;
}

void A::change_name(std::string str)
{
	std::string tmp = get_name();
	set_name(tmp + "+" + str);
}

B::B (std::string str)
	: baseA(str)
{}

B::~B()
{}

void B::mega_fun()
{
	std::cout << "object name is:" << get_name()  << std::endl;
}

