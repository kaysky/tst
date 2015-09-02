#include<iostream>

using namespace std;

class base
{

public:

    base()
    {
        cout << "base Constructor" << endl;
    }

    virtual ~base()             //virtual is nessosary to call child destructor through base pointer
    {
        cout << "base Destructor" << endl;
    }
};

class child : public base
{

public:
    child()
    {
        cout << "child Constructor" << endl;
    }

    ~child()
    {
        cout << "child Destructor" << endl;
    }
};

class A :public child
{
	public:
		A() { std::cout << "A constructor" << std::endl; }
		~A() { std::cout << "A destructor" << std::endl; }
};

int main()
{
    cout << "base pointer:" << endl;
    base *pb = new child();
    delete pb;
    pb = new A();
    delete pb;
    cout << "objects" << endl;
    child ob = child();
    return 0;
}
