#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <typeinfo>
#include <set>
#include <algorithm>


using namespace std;

struct fontController
{
    int l,h;
    const string letters;
    map<char,vector<string>> font;

    void print_font_letter(const char ch)
    {
        cout << endl;
        for(const auto& e :font[ch])
        {
            cout << e << endl;
        }
    }

    fontController()
        : letters("ABCDEFGHIJKLMNOPQRSTUVWXYZ?")
    {}

	void init_param(int L, int H)
	{
		l = L;
		h = H;
	}


    void make_font_letter(const string& ROW)
    {
        int i=1;
        string tmp;
        string::const_iterator it = letters.begin();
        for(auto e :ROW)
        {
            if(i < l)
            {
                tmp += e;
                ++i;
            }
            else
            {
                tmp += e;
                font[*it].push_back(tmp);
                tmp.clear();
                i = 1;
                ++it;
            }
        }
    }

    void concat(vector<string>& dst, vector<string>& src)
    {
        if(dst.empty())
        {
            for(const auto& e :src)
            {
                dst.push_back(e);
            }
        }
        else
        {
            vector<string>::iterator it_src = src.begin();
            for( vector<string>::iterator it_dst = dst.begin()
              ; it_dst != dst.end()
              ; ++it_dst, ++it_src
              )
            {
                *it_dst += *it_src;
            }
        }
    }

    void make_art_string(string& str, vector<string>& vstr)
    {
        validate(str);
        for(const auto& e :str)
        {
            auto it =  font.find(e);
            if(it != font.end())
            {
                concat(vstr,it->second);
            }
        }
    }

    void validate(string& str)
    {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        for(auto it = str.begin(); it != str.end(); ++it)
        {
            if(letters.find(*it) == string::npos)
                *it = '?';
            else
                continue;
        }
    }


};



int main(int argc, char *argv[])
{
	string T;
	int L;
	int H;
	vector<string> art;
	fontController fc;

	std::cout << "test of user's FONT" << std::endl;

	ifstream in("in2.txt");

	if(in.is_open())
	{
		in >> L;
		in >> H;
		in >> T;
		fc.init_param(L,H);
		string ROW;
		while(getline(in,ROW))
		{
			cout << ROW << endl;
			fc.make_font_letter(ROW);
		}


		for(const auto& e :T)
		{
			fc.print_font_letter(e);
		}

		fc.make_art_string(T,art);

		std::cout << "input string is : " << T << std::endl;
		std::cout << "output art is : " << std::endl;
		for(const auto& e :art)
		{
			cout << e << endl;
		}
	}

	std::cout << "end of the test" << std::endl;
	return 0;
}
