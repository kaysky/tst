#include <iostream>
#include "fman.hpp"

using namespace std;
using namespace kki;


int main(int argc, char *argv[])
{
	std::cout << "FMAN test:" << std::endl;

	FMan fman("in.tmp","out.tmp");

//	fman.direct_sort();
	std::cout << fman.detect_free_ram() << endl;
	std::cout << fman.detect_file_size() << std::endl;
//	fman.merge2files();


	std::cout << "End of the test." << std::endl;
	return 0;
}
