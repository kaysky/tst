#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

pair<string,string> parse_mime(const string& str)
{
	pair<string,string> pr;
	string tmp;
	stringstream ss(str);
	ss >> tmp;
	for_each(tmp.begin(), tmp.end(), [](char& in){ in = ::tolower(in);});
	pr.first = tmp;
	ss >> tmp;
	pr.second = tmp;
	return pr;
}

string parse_ext(const string& str)
{
	string tmp;
	int q = count(str.begin(),str.end(),'.');
	if(q >= 1)
	{
		tmp = str.substr(str.find_last_of('.')+1);
	}
	for_each(tmp.begin(), tmp.end(), [](char& in){ in = ::tolower(in); });
	return tmp;
}


/*  string parse_ext(const string& str)
{
	string tmp;
	size_t n = str.find('.');
	if(n != string::npos)
	{
		tmp = string(str, n+1);
		for_each(tmp.begin(), tmp.end(), [](char& in){ in = ::tolower(in);});
	}
	return tmp;
}*/



int main(int argc, char *argv[])
{
	std::cout << "tets of mimitype ..." << std::endl;

	ifstream in("in.txt");

	int N;
	int Q;
	string tmp;
	map<string,string> table;

	if(in.is_open())
	{
		int i = 0;
		in >> N;
		in >> Q;
		while(getline(in,tmp))
		{
			//std::cout << tmp << std::endl;
			if(i <= N)
			{
				//do map table
				table.insert(parse_mime(tmp));
			}
			else
			{
				//read file names
				//files.push_back(tmp);
			//	std::cout << parse_ext(tmp) << endl;
				const auto it = table.find(parse_ext(tmp));
				if(it != table.end())
				{
					cout << it->second << endl;
				}
				else
					cout << "UKNOWN" << endl;
			}
			++i;
		}
	}

	ifstream in_ext("ext.txt");
	ofstream out("out.txt");

	if(in_ext.is_open() && out.is_open())
	{
		string tmp;
		while(getline(in_ext,tmp))
		{
			out << parse_ext(tmp) << endl;
			//out >> tmp >> endl;
		}
	}

	std::cout << "end of the test." << std::endl;
	return 0;
}
