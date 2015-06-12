#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void th_fun()
{
    cout << "HELLO FROM THREAD" << endl;
    for(int i = 0; i < 10; ++i)
    {
	sleep(1);
        cout << "child i # : " << i << endl;
    }
}

int main()
{
    thread th(th_fun);
    cout << "THAT IS TEST G++11" << endl;
    
    for(int i = 0; i < 10; ++i)
    {
	sleep(1);
        cout << "parant i # : " << i << endl;
    }
    
    th.join();

return 0;
}