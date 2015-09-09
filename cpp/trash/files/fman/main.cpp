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

//	std::cout << "generate file" << std::endl;
//	randFile file("test.in",1000000);
//	file.gnFile();

//	file.readFile();
//	fman.direct_sort();

//	string a("a");
//	string b("b");
//	string c("c");


//	fman.merge2files(a,b,c);

	fman.split2tmp();
	fman.sort_tmp();
	std::cout << "merging tmp files:" << std::endl;
	fman.mergeTmpFiles();

	std::cout << "End of the test." << std::endl;
	return 0;
}
