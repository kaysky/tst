#include <iostream>

using namespace std;

class intWrapper
{
	int v_;

	public:

		intWrapper(int a) :v_(a)
		{
			std::cout << "wrapper constructor." << std::endl;
		}

		intWrapper(const intWrapper& rvl)
		{
			v_ = rvl.v_;
			std::cout << "COPY wrapper constructor" << std::endl;
		}

		intWrapper& operator=(intWrapper &rvl)
		{
			std::cout << "operator=intWraper" << std::endl;
			v_ = rvl.v_;
			return *this;
		}

		intWrapper& operator=(int rvl)
		{
			std::cout << "operator=int" << std::endl;
			v_ = rvl;
			return *this;
		}
		operator int()
		{
			std::cout << "cast operator to int" << std::endl;
			return v_;
		}
};

int main(int argc, char *argv[])
{
	std::cout << "test cast operator ..." << std::endl;

	int a = 10;
	intWrapper	wrap(0);
	intWrapper	wrap2 = 1;
	wrap = 2;
	wrap2 = wrap;
	a = wrap2;

	std::cout << "a = " << a << std::endl;
	//std::cout << "wrap = " << wrap << std::endl;
	//std::cout << "wrap2 = " << wrap2 << std::endl;

	std::cout << "end of the test." << std::endl;
	return 0;
}
