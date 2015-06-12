#ifndef __OBSERVER__HPP__

#define __OBSERVER__HPP__

#include <iostream>
#include <list>
#include <memory>


namespace kki
{

class Subject;
class Observer;

typedef	std::shared_ptr<Observer> Obs;
typedef std::list<Obs> list_of_observers;

/*
 *	That is common interface of "Observer" pattern
 *  we may use is to create particular observers.
 *  aID - is unnecessary part for indification of objects
*/
class Observer
{
	public:
		virtual ~Observer();

		/*
		 * Must be implemented in subclusses
		*/
		virtual void update() = 0;

		/*
		 *	Returns particular ID of observer
		 *	I use this only to control creation and destroying
		 *	statistic of subclasses and for removing of particular
		 *	observer from the list of the Subjects.
		*/
		int get_id() { return aID; }

	protected:
		Observer(int id);

	private:
		int aID;
};

/*
 *	That is common interfase of "Subject"
 *	It is a part of "Observer" pattern
 *	We may use it to creat particular
 *	Subjects or additional events.
*/
class Subject
{
	public:
		/*
		 *	Don't forget using virtual destructors for any Base classes
		*/
		virtual ~Subject();

		/*
		 *	F-n adds new subscriber(observer) to the list of the Subject
		*/
		virtual void attach(Obs);

		/*
		 *	F-n deletes particular observer from the list
		*/
		virtual void detach(Obs);

		/*
		 *	F-n informs all observers about some event
		*/
		virtual void notify();

	protected:
		/*
		 *	We make constructor protected in order to forbid to create
		 *	subject directly
		*/
		Subject();

	private:
		/*
		 *	It keeps list of all added observers.
		 *	It may have different types of realisation
		 *	and makes it the most interesting part of
		 *	"Observer" pattern.
		 *
		*/
		list_of_observers observers;
};

//*****************************************************************************
/*
 * Helpers. They are used to serve "Observer" pattern
*/
//*****************************************************************************

/*
 * Functor searches of particular observer based on its own ID
*/
class find_obs
{
		int aId;
	public:
		find_obs(int id);
		~find_obs() {}
		bool operator()(Obs);
};

/*
 *	Functor informs particular observer about event
*/
class do_notify
{
	public:
		do_notify() {}
		~do_notify() {}
		void operator()(Obs aObs) { aObs->update(); }
};


};

#endif //__OBSERVER__HPP__
