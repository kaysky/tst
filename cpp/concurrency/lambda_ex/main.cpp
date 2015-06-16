/*
 *
 *
 *
 *      g++ main.cpp -o ttt -pthread -std=c++11
 *
*/

#include <cstdlib>
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

using namespace std;

void hello ()
{
	std::cout << "hello from concurency" << std::endl;
}


void fun(int &i)
{

    i  = i + 1;
}

int main()
{

    cout << "test:" << endl;
    std::thread th(hello);
    th.join();                //not working



//    vector<int> v(10,1);
//    vector<int>::const_iterator it,it_end;

//    std::for_each(v.begin(),v.end(),[](int i){cout << i << endl;});
//    std::for_each(v.begin(),v.end(),fun);
//    for ( it = v.begin()
//         ,it_end = v.end()
//         ; it != it_end
//         ; ++it)
//        cout << *it << "  ";

    cout << endl;
    return 0;
}
