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
				indirect_sort();
			}

			default:
			{

			}
		}
	}

	void FMan::direct_sort()
	{
		if(detect_file_size() < detect_free_ram())
		{
			std::string str("");
			std::ifstream in(infile);
			std::ofstream out(outfile);
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
		else
		{
			indirect_sort();
		}
	}


	void FMan::indirect_sort()
	{
		//take mem info and some prediction
		split2tmp();
		mergeTmpFiles();
		uFgen->delFlist();
	}


	unsigned int FMan::detect_free_ram()
	{
		std::string tmp("");
		std::ifstream in("/proc/meminfo");
		std::istringstream iss;
		std::vector<std::string> ramInf;
		while(!in.eof())
		{
			std::getline(in,tmp);
			if(!tmp.find("MemFree"))
			{
				//ramInf.push_back(tmp);
				iss.str(tmp);
				copy( std::istream_iterator<std::string>(iss)
					, std::istream_iterator<std::string>()
					, std::back_inserter(ramInf)
					);
				std::cout << tmp << std::endl;
				std::cout << "size of free mem in Kb :" << ramInf[1] << std::endl;
				break;
			}
		}
		in.close();
		int val = std::stoi(ramInf[1]);
		return val;
	}

	unsigned int FMan::detect_file_size()
	{
		std::ifstream file(infile, std::ios::binary | std::ios::ate);
		int val = file.tellg();
		file.close();
		return val;
	}


	void FMan::split2tmp()
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

	void FMan::mergeTmpFiles()
	{
		std::fstream tmp;
		std::ifstream ifs;
		std::fstream out;

		for(const auto& it :uFgen->getFlist())
		{
			tmp.open("t0.tmp",std::fstream::out);
			out.open(outfile,std::fstream::in);

			if(tmp.is_open() && out.is_open())
			{
				std::copy( std::istream_iterator<std::string>(out)
						 , std::istream_iterator<std::string>()
						 , std::ostream_iterator<std::string>(tmp,"\n"));
			}
			tmp.close();
			out.close();

			tmp.open("t0.tmp",std::fstream::in);
			ifs.open(it);
			out.open(outfile,std::fstream::out);

			if(	tmp.is_open()
					&&
				out.is_open()
					&&
				ifs.is_open()
			  )
				std::merge( std::istream_iterator<std::string>(tmp)
						  , std::istream_iterator<std::string>()
						  , std::istream_iterator<std::string>(ifs)
						  , std::istream_iterator<std::string>()
						  , std::ostream_iterator<std::string>(out,"\n")
						  );
			tmp.close();
			ifs.close();
			out.close();
		}
	}

};
