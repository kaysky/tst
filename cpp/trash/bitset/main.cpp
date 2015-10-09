#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

	const int N = 7;

class norris
{
	//get ready bin repr for ferther encoding (makes chunk of values)
	void split2chunk(const string& str, vector<string>& vchunk)
	{
		string tmp;
		char ch = str[0];

		for(int i = 0; i < str.length(); ++i)
		{
			if(ch == str[i])
				tmp += str[i];
			else
			{
				ch = str[i];
				vchunk.push_back(tmp);
				tmp.clear();
				tmp += str[i];
			}
		}
		vchunk.push_back(tmp);
	}

	//encoder of norris algorithm
	string encode2str(vector<string>& vs)
	{
		int q{0};
		string tmp;

		for(const auto& e :vs)
		{
			q = count(e.begin(),e.end(),'1');

			if(q == 0)
				tmp += "00 " + e + " ";
			else
				tmp += "0 " + string(q,'0') + " ";
		}
		tmp.erase(tmp.end()-1);
		return tmp;
	}

public:

	// makes binarry represantation of ordinary string
	string str2bin_str(const string& str)
	{
		string tmp;
		for(const auto& e :str)
		{
			bitset<N> bs(e);
			tmp += bs.to_string();
		}
		return tmp;
	}

	string binstr2str(const string& str)
	{
		string tmp;
		for(int i = 0; i < str.length(); i +=7)
		{
			bitset<N> bs(string(str,i,7));
			tmp +=  (char)bs.to_ulong();
		}
		return tmp;
	}

	// ecode input string to output string with norris' algorithm
	string encode(const string& str)
	{
		string tmp = str2bin_str(str);
		vector<string> vch;
		split2chunk(tmp,vch);
		return encode2str(vch);
	}

	string decode(const string& sstr)
	{
		string tmp;
		stringstream ss(sstr);
		vector<string> codes;
		vector<string> values;

		cout << "decoder str: ";
		int i = 0;
		while(ss >> tmp)
		{
			if(i%2)
			{
				values.push_back(tmp);
				cout << tmp << " ";
			}
			else
			{
				codes.push_back(tmp);
				cout << tmp << " ";
			}
			++i;
		}
		cout << endl;

//			cout << "codes/values : ";
		int q = 0;
		tmp.clear();
		for(int i = 0; i < values.size(); ++i)
		{
//			cout << codes[i] << "/" << values[i] << " ";
			if(codes[i] == "0")
			{
				q = count(values[i].begin(),values[i].end(),'0');
//				cout << "i:" << i << " q:" << q << " ";
				tmp += string(q,'1');
			}
			else if(codes[i] == "00")
				tmp += values[i];
		}
		std::cout << std::endl;

		return binstr2str(tmp);
	}
};



int main(int argc, char *argv[])
{
	std::cout << "test bit set :" << std::endl;

	norris nr;
	string str("Chuck Norris is the best of the best of the best 1010101010101");
	std::cout << "in str: " << str << std::endl;
	std::cout << "bin represantation: " << nr.str2bin_str(str) << std::endl;
	string sstr = nr.encode(str);
	std::cout << "encoded str: " << sstr << endl;
	sstr = nr.decode(sstr);
	cout << "decoded str: " << sstr << endl;
//	cout << nr.binstr2str(sstr);

	std::cout << "end of the test" << std::endl;
	return 0;
}
