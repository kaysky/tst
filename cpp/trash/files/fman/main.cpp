#include <iostream>
#include "fman.hpp"
#include "randfilegen.hpp"
#include "cmdparce.hpp"


using namespace std;
using namespace kki;



int main(int argc, char *argv[])
{
	std::cout << "FMAN test:" << std::endl;

	cmd parcer;
	parcer.parse_cmd(argc,argv);
//	parcer.show_cmd_line();
	std::cout << "User's limit is :" << parcer.get_limit() << endl;

//	unsigned int limit = 1000000; // 1Mb
	FMan fman(parcer.get_fin(),parcer.get_fout(),parcer.get_limit());

//	std::cout << "generate file" << std::endl;
//	randFile file("test.in",1000000);
//	file.gnFile();


	fman.indirect_sort();

	std::cout << "End of the test." << std::endl;
	return 0;
}
