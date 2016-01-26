#include <iostream>
#include <QObject>
#include <QPointer>

using namespace std;

class A : public QObject
{

    Q_OBJECT

public:
    A(QObject *p = 0) : QObject(p)
    {
	cout << "Constructor ...." << endl;
    }
    
    ~A() 
    {
	cout << "Destructor ...." << endl;
    }
};

int main()
{
	cout << "test prj ..." << endl;

	int *pdd = new int(0.0);
	//delete pdd;
	delete pdd;

    //A *a = new A();
    //delete a;
    QPointer<A> a = new A;
    delete a;

	cout << "end of the test ..." << endl;
	return 0;
}
