#include <iostream>

using namespace std;

class A
{
	static const int N = 3;
	enum {M = 3};
	const int arr[M];
	static const int sarr[N];

public:
	A() :arr{1,2,3} {}

	void print() 
	{
		//cout << sarr[0] << endl; //OK method may get static field
		std::cout << "const array: ";
		for(auto i :arr)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	static void show_sarr(const string & str = "")
	{
		//cout << arr[0];	//compile time error static method trys get not static field
		std::cout << "static const array: ";
		for(auto i :sarr)
		{
			std::cout << i  << " ";
		}
		std::cout << "  "<< str << std::endl;
	}

};

const int A::sarr[3]{0,1,2};

int main(int argc, char *argv[])
{
	std::cout << "test const array in class" << std::endl;

	A a;
	a.print();
	a.show_sarr("a.show_sarr()");
	A::show_sarr("A::show_sarr()");
	std::cout << "end of the test." << std::endl;
	return 0;
}
