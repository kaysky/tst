#include <iostream>
#include "fman.hpp"

using namespace std;
using namespace kki;


int main(int argc, char *argv[])
{
	std::cout << "FMAN test:" << std::endl;

	FMan fman("in.tmp","out.tmp");

	fman.direct_sort();
	fman.show_free_mem();


	std::cout << "End of the test." << std::endl;
	return 0;
}
