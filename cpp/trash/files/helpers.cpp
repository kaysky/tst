#include "helpers.hpp"

namespace kki
{
		

void show_usage(char *arg[])
{
	std::cout << "USAGE of the " << arg[0] << ":"  << std::endl;
	std::cout << arg[0]  << " --help or -h show this message" << std::endl;
	std::cout << arg[0] << " <inputFile>  <outputFile>  [memsize]  sorts input file to output one" << std::endl;
}

bool parse_cmd(int argc, char *arg[], std::vector<std::string> &cmd_line)
{
	if(argc < 2 || argc > 4)
	{
		show_usage(arg);
		return false;
	}

	for(int i = 0; i < argc; ++i)
	{
		cmd_line.push_back(arg[i]);
	}

	if(cmd_line[1] == "--help" || cmd_line[1] == "-h")
	{
		show_usage(arg);
		return false;
	}

	if(cmd_line[1].empty() && cmd_line[2].empty())
		return false;
	else
		return true;
}


};
