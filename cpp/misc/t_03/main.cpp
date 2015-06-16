/*

		test of reference for printing data
		test deligation of constructor needs std=c++11
		test labda and for_each() needs sts=c++11
*/

#include <iostream>
#include <boost/array.hpp>

using namespace std;

struct A
{
	int f1;
	double f2;
	
	A() : A(1) {}

	A(int k)
	{
		f1 = k;
		f2 = k;
	}

	void improve(int k)
	{
		f1 *= k;
		f2 *= k;
	}
};

boost::array<A,10> arr;

void init(boost::array<A,10>  &arr)
{
	for(int i = 0; i < arr.static_size; ++i)
	{
		arr.at(i).improve(i);	
	}
}

void print(boost::array<A,10>  &arr)
{
	for(int i = 0; i < arr.static_size; ++i)
	{
		A const &tmp = arr.at(i);
		cout << " for " << i << " :" << tmp.f1 << " " << tmp.f2 << endl;	
	}
}

void print2(boost::array<A,10>  &arr)
{
	for_each( arr.begin()
		, arr.begin() + size_t(arr.static_size)
		, [](A a){ cout << a.f1 << " " << a.f2 << endl; }
		);
}


int main()
{
	cout << "test reference style :" << endl;

	init(arr);
	print2(arr);

	return 0;
}
