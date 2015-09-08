#include "fman.hpp"

namespace kki
{

/*  	void FMan::merge2files()
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
*/
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

	void FMan::split2double()
	{
		std::ifstream in(infile);
		std::vector<std::string> fsnames{"1.temp","2.temp"};
//		std::string fname1("1.temp");
//		std::string fname2("2.temp");
		std::string tmp("");
		unsigned int in_file_size = detect_file_size();
		unsigned int ram_size = detect_free_ram();
		unsigned int half = in_file_size/2;
		char *bf = NULL;

		std::cout << in_file_size << " "
			 << ram_size << " "
			 << half << std::endl;

		if(half > ram_size)
		{
			std::cout << "ERROR to big file" << std::endl;
			return;
		}

		if(in.is_open())
		{
//			std::cout << "in file is opened!" << std::endl;
//			bf = new char [half];
//			in.read(bf,half);
//			std::ofstream out1(fsnames[0]);
//			out1.write(bf,half);
//			out1.close();
//			delete [] bf;
//
//			in.seekg(half,std::ios_base::beg);
//			int  pos = in.tellg();
//			std::ofstream out2(fsnames[1]);
//			bf = new char[pos];
//			in.read(bf,pos);
//			out2.write(bf,pos);
//			out2.close();
//			delete [] bf;
//
//			while(!in.eof())
//			{
//				if(hsize <= (half/5) )
//				{
//					getline(in,tmp);
//					buff.insert(tmp);
//				}
//				else
//				{
//					std::cout << "hsize is : " << hsize << std::endl;
//					uFgen->addFile(fsnames[idx],buff);
//					buff.clear();
//				}
//
//			}
		}
	}


/* /	void FMan::split2tmp()
	{
		std::ifstream in(infile);
		std::string tmp("");
		std::string name("");
		int idx(0);
		int qmem(0);
		int QmemAllowed = detect_free_ram() * 0.8;
		if(in.is_open())
		{
			while(!in.eof())
			{
				qmem += tmp.size();
				if(qmem <= QmemAllowed)
				{
					std::getline(in,tmp);
					buff.insert(tmp);
				}
				else
				{
					idx += 1;
					name = std::to_string(idx) + ".tmp";
					uFgen->addFile(name,buff);
					buff.clear();
					qmem = 0;
				}
			}
		}
	}

*/


};
