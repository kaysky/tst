/*
 *
 *          This exemple shows an interesting way of work with
 *          an object which has pointer field and how to work
 *          with the field if we have pointer to some objects
 *
 *
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct profile
{
    string name;
    unsigned int age;
    string *department; //field pointer
    profile(string str, int a, string *dep) : name(str), age(a), department(dep)
    {}
};

int main()
{
    cout << "Test program some poiners" << endl;

    string dep("R&D");
    profile pf("Fedor",40,&dep);

    cout << pf.name << " " << pf.age << " " << *(pf.department) << endl; // I-st way
    cout << pf.name << " " << pf.age << " " << *pf.department << endl; // II-d way

    // pointer to object
    profile *ppf = &pf;

    cout << "pointer to the object" << endl;
    cout << ppf->name << " " << ppf->age << " " << *(ppf->department) << endl; // I-st way
    cout << (*ppf).name << " " << (*ppf).age << " " << *(*ppf).department << endl; // II-d way

    return 0;
}
