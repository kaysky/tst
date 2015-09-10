#include "cmdparce.hpp"

namespace kki
{


void cmd::show_usage(char *arg[])
{
	std::cout << "USAGE of the " << arg[0] << ":"  << std::endl;
	std::cout << arg[0]  << " --help or -h show this message" << std::endl;
	std::cout << arg[0] << " <inputFile>  " << std::endl;
	std::cout << arg[0] << " <inputFile>  <outputFile>  " << std::endl;
	std::cout << arg[0] << " <inputFile>  <outputFile>  [memsize] Mb  sorts input file to output one" << std::endl;
}

bool cmd::parse_cmd(int argc, char *arg[])
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

	if(argc == 2)
	{
		inFileName = cmd_line[1];
		outFileName = inFileName + ".sorted";
		mem_limit = dflim;
		return true;
	}

	if(argc == 3)
	{
		inFileName = cmd_line[1];
		outFileName = cmd_line[2];
		mem_limit = dflim;
		return true;
	}

	if(argc == 4)
	{
		try
		{
			inFileName = cmd_line[1];
			outFileName = cmd_line[2];
			mem_limit = std::stoi(cmd_line[3]);
			if(mem_limit == 0) mem_limit = dflim;
			mem_limit = mem_limit < dflim ? mem_limit : dflim;
			return true;
		}
		catch(const std::invalid_argument& ia)
		{
			std::cout << "!!!ERROR: 3d parameter must be a number!" << std::endl;
			exit(1);
		}
	}

}

void cmd::show_cmd_line()
{
	for(const auto& e:cmd_line)
	{
		std::cout << e << std::endl;
	}
}

};
