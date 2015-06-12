#include "my_smart_ptr.hpp"
#include <iostream>

struct A
{
	int		a;
	double	b;
	A(int n, double nn) : a(n), b(nn) {}
};

template<class T>
kos::MySmartPtr<T> fun_for_call_of_copyconstructor(kos::MySmartPtr<T> p)
{
	std::cout << p;
	return p;
}

int main(int argc, char *argv[])
{
	std::cout << "test my smart ptr" << std::endl;

//	kos::MySmartPtr<int> ob(new int(10) );
	kos::MySmartPtr<A> a(new A(11,20.5));

//	std::cout << ob	<< std::endl;
//	std::cout << *ob << std::endl;

	std::cout << a << std::endl;
	std::cout << "A::a :" << a->a << std::endl;
	std::cout << "A::b :" << (*a).b	<< std::endl;

	fun_for_call_of_copyconstructor<A>(a);
	std::cout << "ref for a :" << a << std::endl;
	//std::cout << "ref for a2:" << a2 << std::endl;
	kos::MySmartPtr<A> a2;
	kos::MySmartPtr<A> a3;
	std::cout << "ref for a2 :" << a2 << std::endl;
	a2 = a;
	std::cout << "ref for a :" << a;
	std::cout << "ref for a2 :" << a2;
	a3 = a2;
	std::cout << "ref for a :" << a;
	std::cout << "ref for a2 :" << a2;

	std::cout << "end of the test" << std::endl;
	return 0;
}
