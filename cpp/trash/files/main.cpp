#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void show_usage(char *arg[])
{
	std::cout << "USAGE of the " << arg[0] << ":"  << std::endl;
	std::cout << arg[0]  << " --help or -h show this message" << std::endl;
	cout << arg[0] << " <inputFile>  <outputFile>  [memsize]  sorts input file to output one" << endl;
}

bool parse_cmd(int argc, char *arg[], vector<string> &cmd_line)
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


int main(int argc, char *argv[])
{
	std::cout << "test streams" << std::endl;

	vector<string> cmd_line;
	if(!parse_cmd(argc,argv,cmd_line))
	{
		cout << "wrong parameters to sort a file" << endl;
		return 1;
	}

	string sLine = "";
	ifstream in;
	ofstream out;
	multiset<string> ls;

	out.open(cmd_line[2]); //fstream::out)
	in.open(cmd_line[1]);

	while(!in.eof())
	{
		getline(in, sLine);
		ls.insert(sLine);
		cout << sLine << endl;
	}

	ostream_iterator<string> itr (out, "\n");

	copy(ls.begin(), ls.end(), itr);

	for(const auto& e :ls)
	{
		std::cout << e << std::endl;
	}

	out.close();
	in.close();

	cout << "Read file completed!!" << endl;


	std::cout << "end of the test." << std::endl;
	return 0;
}
