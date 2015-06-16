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

int main()
{
    cout << "base pointer:" << endl;
    base *pb = new child();
    delete pb;
    cout << "objects" << endl;
    child ob = child();
    return 0;
}
