#include <iostream>


using namespace std;


class second;
class first
{
public:
	first(const second &snd) : nd(snd)
	{}
private:
	const second &nd;
};


class second
{
	first fr;
public:
	second() :fr(*this)
	{
	}
};


int main(int argc, char *argv[])
{
	std::cout << "tets forward declaration ..." << std::endl;

	second nd;
	first fr(nd);

	std::cout << "End of the test." << std::endl;
	return 0;
}
