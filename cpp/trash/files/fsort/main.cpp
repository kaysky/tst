
#include "helpers.hpp"

using namespace std;
using namespace kki;


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
