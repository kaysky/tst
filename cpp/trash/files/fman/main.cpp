#include <iostream>
#include "fman.hpp"
#include "randfilegen.hpp"


using namespace std;
using namespace kki;



int main(int argc, char *argv[])
{
	std::cout << "FMAN test:" << std::endl;

	unsigned int limit = 1000000; // 1Mb
	FMan fman("test.in","sortedOut.tmp", limit*50);

//	randFile file("test.in",1000000);
//	file.gnFile();

//	file.readFile();
//	fman.direct_sort();
	fman.split2tmp();
	fman.sort_tmp();
	std::cout << "merging tmp files:" << std::endl;
	fman.mergeTmpFiles();

	std::cout << "End of the test." << std::endl;
	return 0;
}
