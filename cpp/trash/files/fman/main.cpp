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

//	std::cout << "generate file" << std::endl;
//	randFile file(parcer.get_fin(),210);
//	file.gnFile();

	FMan fman(parcer.get_fin(),parcer.get_fout(),parcer.get_limit());

	fman.proceed_sort();

	return 0;
}
