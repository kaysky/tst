
#include "observer.hpp"
#include <algorithm>


namespace kki
{

/*
 *	Different observers should have different unic IDs
 *	It inits observer with particular ID
*/
Observer::Observer(int id)
	: aID(id)
{
	std::cout << "created observer id :" << aID << std::endl;
}

Observer::~Observer()
{
	std::cout << "destroyed observer id :" << aID << std::endl;
}

/*
 *	Init functor with particular ID of observer
 *	(we use it to look for observer in the list)
*/
find_obs::find_obs(int id)
	: aId(id)
{}

/*
 * returns true for particular observer
*/
bool find_obs::operator()(Obs aObs)
{
	return aId == aObs->get_id();
}

Subject::Subject()
{
}

Subject::~Subject()
{
}

/*
 * F-n adds observer to the list
*/
void Subject::attach(Obs aObs)
{
	observers.push_back(aObs);
}

/*
 *	F-n deletes particular observer with "remove_if" algorithm
 *	It has linear complexity
*/
void Subject::detach(Obs aObs)
{
	find_obs dt(aObs->get_id());
	observers.remove_if(dt);
}

/*
 * F-n informs all observer in the list
 * calls *->update function for all participants
*/
void Subject::notify()
{
	for_each(observers.begin(), observers.end(), do_notify());
}


};
