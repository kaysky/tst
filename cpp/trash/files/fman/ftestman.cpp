#include "fman.hpp"

namespace kki
{

	void FMan::merge2files()
	{
		std::ifstream in1("a.test");
		std::ifstream in2("b.test");
		std::ofstream out("ab.test");
		std::merge( std::istream_iterator<std::string>(in1)
				  , std::istream_iterator<std::string>()
				  , std::istream_iterator<std::string>(in2)
				  , std::istream_iterator<std::string>()
				  , std::ostream_iterator<std::string>(out,"\n")
				  );
	}

	void FMan::testCopyFile()
	{
		std::ifstream in(infile.c_str());
		std::ofstream out(outfile.c_str());
		if(in.is_open())
		{
			if(out.is_open())
			{
				std::copy( std::istream_iterator<std::string>(in)
						 , std::istream_iterator<std::string>()
						 , std::ostream_iterator<std::string>(out,"\n"));
			}
		}
		in.close();
		out.close();
	}

};
