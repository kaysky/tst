#include "alib.hpp"
#include "blib.hpp"

#include <vector>
#include <algorithm>

using namespace std;

class functor
{
public:
	functor() {}
	~functor() {}
	void operator()(baseA *p)
	{
		p->mega_fun();
	}
};
functor fn;

template<class type>
void display(type t)
{
	for_each(t.begin(), t.end(), fn);
}

int main()
{
	std::cout << "test prg for vim oractice." << std::endl;

	vector<baseA*> lst;
	A *a = new A("A");
	B *b = new B("B");
	C *c = new C("C");
	D *d = new D("D");

	lst.push_back(a);
	lst.push_back(b);
	lst.push_back(c);
	lst.push_back(d);

//	for_each(lst.begin(), lst.end(), fn);
	display(lst);
	a->change_name("a");
	display(lst);



	delete a;
	delete b;
	delete c;
	delete d;

	std::cout << "end test prg." << std::endl;
	return 0;
}
