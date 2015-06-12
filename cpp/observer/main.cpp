/*
 *	That is exemple of use "observer" pattern
 *
*/

#include "exemple_use.hpp"

using namespace exemple;

int main()
{
	std::cout << "test prj of OBSERVER pattern " << std::endl;

	//Create subject for observetion
	exemple::timer sb;

	//Create observers
	std::shared_ptr<A> a(new A(1));		//created observer id :1
	std::shared_ptr<B> b(new B(2));		//created observer id :2
	std::shared_ptr<C> c(new C(3));		//created observer id :3

	// Add observers to the list of subject
	sb.attach(a);
	sb.attach(b);
	sb.attach(c);

	// Subject informs the observers about an event
	// some event* happaned*
	sb.notify();

	std::cout << "end of the test " << std::endl;
	return 0;
}

/*
 *		EXPECTED OUTPUT:
 *
 *	test prj of OBSERVER pattern
 *	created observer id :1
 *	created observer id :2
 *	created observer id :3
 *	A informed about event of subject
 *	B informed about event of subject
 *	C informed about event of subject
 *	end of the test
 *	destroyed observer id :1
 *	destroyed observer id :2
 *	destroyed observer id :3
 *
 *
 *
*/
