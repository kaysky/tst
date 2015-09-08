#include <iostream>
#include "fman.hpp"
#include "randfilegen.hpp"


using namespace std;
using namespace kki;


list<int> ls;

void funls()
{
	ls.push_back(0);
	ls.push_back(1);
	ls.push_back(2);

	int i = 2;
	for(const auto& e :ls)
	{
		++i;
		std::cout << e << std::endl;
		if(i < 10) ls.push_back(i);
	}
}

int main(int argc, char *argv[])
{
	std::cout << "FMAN test:" << std::endl;

	unsigned int limit = 1000000; // 1Mb
	FMan fman("test.in","sortedOut.tmp", limit*50);
//	randFile file("test.in",1000000);

//	file.gnFile();
//	file.readFile();
//	fman.direct_sort();
//	std::cout << "free ram in B: " << fman.detect_free_ram() << endl;
	//std::cout << "mem size in B: " << fman.detect_file_size() << std::endl;

//	fman.in2out();
//	fman.split2double();
//	fman.merge2files();
	fman.split2tmp();
//	fman.direct_sort();

//	funls();

	std::cout << "End of the test." << std::endl;
	return 0;
}
