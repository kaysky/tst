#ifndef __MY_SMART_PTR_HPP

#define  __MY_SMART_PTR_HPP

#include <iostream>
#include <string>
#include <typeinfo>


namespace kos
{

template<class T>
class MySmartPtr
{
	typedef	T* 		Ptr;
	Ptr				the_ptr;
	unsigned int 	ref_count;
	std::string 	obj_name;

public:
	MySmartPtr() :ref_count(0) {}

	MySmartPtr(Ptr tp)
		: the_ptr(tp)
		, ref_count(0)
		, obj_name("constructor")
	{
		++ref_count;
		std::cout << obj_name << std::endl;
	}

	MySmartPtr(const MySmartPtr& rp)
		: ref_count(rp.ref_count)
		, obj_name("copy constructor")
		, the_ptr(rp.the_ptr)
	{
		++ref_count;
		std::cout << obj_name << std::endl;
	}

	~MySmartPtr()
	{
		--ref_count;

		if(0 == ref_count)
		{
			std::cout << "ref_count of " /*  << typeid(*this).name()*/ << " is :" << ref_count << std::endl;
			if(the_ptr)
			{
				delete the_ptr;
				std::cout << "the_ptr was released" << std::endl;
			}
		}

		std::cout << "destructor of " << obj_name << std::endl;
	}

	Ptr operator->() { return the_ptr; }
	T& operator*() { return *the_ptr; }



	MySmartPtr& operator=(MySmartPtr& rp)
	{
		std::cout << "operator=" << std::endl;
		++rp.ref_count;
		the_ptr = rp.the_ptr;
		obj_name = "operator=";
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, MySmartPtr<T>& ptr)
	{
		os << "ref_count :" << ptr.ref_count << std::endl;
		return os;
	}


};

//template<class T>
//std::ostream& operator<<(std::ostream& os, MySmartPtr<T> ptr)
//{
//	os << "ref_count :" << ptr.ref_count << std::endl;
//	return os;
//}
//
};


#endif // __MY_SMART_PTR_HPP
