#include <iostream>
#include <array>
using namespace std;

int ch[3]
{
	500,
	600,
	700
} ;

array<int,6> ar;

int main()
{
	std::cout << "tets prg" << std::endl;
	int arr[5] = {0,1,2,3,4};
	for(int &i: arr) cout << i << endl;
	for(int &i: ch) cout << i << endl;
	cout << "=== ++i ===" << endl;
	for(int i = 0; i < 6; ++i) cout <<  i << endl;
	cout << "=== i++ ===" << endl;
	for(int i = 0; i < 6; i++) cout <<  i << endl;

	cout << "=== array ===" << endl;
	for(int i = 0; i < 6; ++i)
	{
		cout << "id [" << i << "] = " << ar.at(i) << endl;
	}

	return 0;
}
