/*
		read files with witespaces line by line (not word by word!)

*/

//#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>


using namespace std;

class mystring :public string
{
	friend istream& operator>>(istream &is, mystring &mystr)
	{
		return getline(is,mystr);
	}
};

int main(int argc, char *argv[])
{
	std::cout << "test sort file with whitespaces" << std::endl;

	ifstream in("in.txt");
	string tmp("");

	vector<string> vstr;
   	/* istream_iterator<string>(in)
					 , istream_iterator<string>()
					 );*/

//	while(!in.eof())
//	{
//		getline(in,tmp);
//		cout << tmp << endl;
//	}

//	in >> std::noskipws;
	copy( istream_iterator<mystring>(in)
		, istream_iterator<mystring>()
		, back_inserter(vstr)
		);

	for(const auto &e :vstr)
	{
		std::cout << e << std::endl;
	}

	std::cout << "end of the test." << std::endl;
	return 0;
}
