#include "blib.hpp"

C::C(std::string str)
	: baseA(str)
{}

C::~C()
{}

void C::mega_fun()
{
	std::cout << "object name is:" << get_name() << std::endl;
}

D::D(std::string str)
	: baseA(str)
{}

D::~D ()
{}

void D::mega_fun()
{
	std::cout << "object name is:" << get_name()  << std::endl;
}


