#include <iostream>
#include "fman.hpp"
#include "randfilegen.hpp"
#include "cmdparce.hpp"


using namespace std;
using namespace kki;



int main(int argc, char *argv[])
{
	cmd parcer;
	if(!parcer.parse_cmd(argc,argv))
	{
		std::cout << "enter parameters please!" << std::endl;
		return 1;
	}

	FMan fman(parcer.get_fin(),parcer.get_fout(),parcer.get_limit());

	fman.proceed_sort();

//	std::cout << "generate file" << std::endl;
//	randFile file("test.in",1000000);
//	file.gnFile();
	return 0;
}
