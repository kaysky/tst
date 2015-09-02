#include <iostream>
#include <set>

using namespace std;

struct A
{
	int	a;
	double	b;
	
	friend bool operator<(const A& lv, const A& rv)
	{
	    return ((lv.a < rv.a) && (lv.b < rv.b));
	}
};

void set_init(set<A> &col, int a, double b)
{
	A tmp = {a,b};
	col.insert(tmp);
}

int main(int argc, char *argv[])
{
	std::cout << "test set<>" << std::endl;

	//A a1,a2;
	set<A> col;
	
	//col.insert(a1);
	//col.insert(a2);

	set_init(col,10,10.0);
	set_init(col,20,20.0);

	for(const auto& l: col)
	{
		std::cout << l.a << " " << l.b << std::endl;
	}

	std::cout << "end of the test." << std::endl;
	return 0;
}
