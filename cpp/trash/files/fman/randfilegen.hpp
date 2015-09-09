#ifndef __RANDOM_FILE_GENERATOR__

#define __RANDOM_FILE_GENERATOR__
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


namespace kki
{

class randFile
{
	static const char randStr[];
	std::string fname;
	std::string tmp;
	int sz;

public:
	randFile(std::string name, int s)
		: fname(name)
		, sz(s)
	{

	}

	void readFile()
	{
		std::string tmp("");
		std::ifstream in("myfile");
		if(in.is_open())
		{
			while(!in.eof())
			{
				getline(in,tmp);
				std::cout << tmp << std::endl;
			}
		}
	}
	void gnFile()
	{
		std::ofstream out(fname);
		int len(50);
		int fileSize = 110 * 1000000; //first diget is Mb
		tmp = "";
		if(out.is_open())
		{
			for(int i = 0; i < fileSize/len; ++i)
			{
				for(int i = 0; i < len; ++i)
				{
					tmp += randStr[rand() % 57];
				}
				out << tmp << std::endl;
				tmp = "";
			}
		}
	}
};

const char randFile::randStr[]{
					   	"abcdghigklmnpqrstuvwxyz"
					  	"0123456789"
					  	"ABCDGHIJKLMNPQRSTUVWXYZ"
					 	};
};



#endif
