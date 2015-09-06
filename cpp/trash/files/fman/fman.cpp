#include "fman.hpp"

namespace kki
{

	void TempFileGenerator::addFile(const std::string &fname, RAMBuff &rambuff)
	{
		std::ofstream out(fname);
		if(out.is_open()) fnames.push_back(fname);
		std::ostream_iterator<std::string> out_it (out,"\n");
		std::copy (rambuff.begin(), rambuff.end(), out_it);
		out.close();
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


	void TempFileGenerator::delFlist()
	{
		for(const auto& e :fnames)
		{
			std::remove(e.c_str());
		}
	}

	void FMan::sort_case(way ws)
	{
		switch(ws)
		{
			case direct:
			{
				direct_sort();
			}

			case split:
			{

			}

			default:
			{

			}
		}
	}

	void FMan::direct_sort()
	{
		std::string str("");
		std::ifstream in(infile.c_str());
		std::ofstream out(outfile.c_str());
		if(in.is_open())
		{
			while(!in.eof())
			{
				std::getline(in,str);
				buff.insert(str);
			}

			if(out.is_open())
				if(!buff.empty())
					copy( buff.begin()
						, buff.end()
						, std::ostream_iterator<std::string>(out,"\n")
						);
		}
	}

	void FMan::show_free_mem()
	{
		std::string tmp("");
		std::ifstream in("/proc/meminfo");
		std::vector<std::string> ramInf;
		while(!in.eof())
		{
			std::getline(in,tmp);
			ramInf.push_back(tmp);
			std::cout << tmp << std::endl;
			if(!tmp.find("MemFree")) break;
		}
		in.close();
		int mem(0);
		std::string::size_type sz;
		//mem = std::stoi(ramInf[1],&sz);
		std::cout 	<< "free mem is:"
					<< mem
					<< " Gb"
					<< std::endl;
	}

	void FMan::split2tmp()
	{
		std::ifstream in(infile);
		std::string tmp("");
		int qmem = 0;
		int QmemAllowed = 200; //Mb
		if(in.is_open())
		{
			while(!in.eof())
			{
				if(qmem <= QmemAllowed)
				{
					std::getline(in,tmp);
					qmem += tmp.size();
					buff.insert(tmp);
				}
				else
				{
					uFgen->addFile("newfilename.tmp",buff);
					buff.clear();
					qmem = 0;
				}
			}
		}
	}


	void FMan::merge4tmp()
	{
		
	}

};
