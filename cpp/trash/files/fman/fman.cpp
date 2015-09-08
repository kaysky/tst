#include "fman.hpp"

namespace kki
{

	void TempFileGenerator::addSortedFile(const std::string &fname, RAMBuff &rambuff)
	{
		std::ofstream out(fname);
		if(out.is_open()) fnames.push_back(fname);
		std::ostream_iterator<std::string> out_it (out,"\n");
		std::copy (rambuff.begin(), rambuff.end(), out_it);
		out.close();
	}

	void TempFileGenerator::delFile(const std::string & name)
	{
		std::remove(name.c_str());
//		fnames.remove(name);
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
		if(detect_file_size(infile) < detect_free_ram())
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
		if(ramInf[2] == "kB")
		{
			std::cout << ramInf[2]  << std::endl;
			val *= 1000;
		}
		return val;
	}

	unsigned int FMan::detect_file_size(const std::string &name)
	{
		std::ifstream file(name, std::ios::binary | std::ios::ate);
		int val(-1);
		if (file.is_open()) val = file.tellg();
		file.close();
		std::cout << "size of " << name << " is :" << val << std::endl;
		return val;
	}


	//to do one big file devide to severel small files
	//which can be sorted internally
	//check size of the file and allowed memram for sorting
	void FMan::split2tmp()
	{
		int idx(0);
		std::string ofName("out");
		unsigned int sys_free_ram = detect_free_ram();
		unsigned int buff_size = user_ram_limitation < sys_free_ram
													 ? user_ram_limitation
													 : sys_free_ram * 0.8;
		std::cout << "buf_size is :" << buff_size << std::endl;
		//int user_limit_ram = user_ram_limitation;
		in2out(infile,ofName);
		for(const auto& e :uFgen->getFlist())
		{
			if(detect_file_size(e) < buff_size)
				continue;
			++idx;
			//ofName += "L" + std::to_string(idx);
			in2out(e,ofName + std::to_string(idx));
		}
	}


	void FMan::in2out(const std::string &inName, const std::string &outName)
	{
		std::string tmp;
		std::string oname1 = outName + "1.tmp";
		std::string oname2 = outName + "2.tmp";
		std::ifstream in(inName);
		std::ofstream out1(oname1);
		std::ofstream out2(oname2);
		int len(0);
		if(in.is_open()
			&& out1.is_open()
			&& out2.is_open()
		  )
		{
			uFgen->addFileName(oname1);
			uFgen->addFileName(oname2);
			while(!in.eof())
			{
				getline(in,tmp);
				++len;
				if(len%2)
					out1 << tmp << std::endl;
				else
					out2 << tmp << std::endl;
			}
		}
		else
			std::cout << "ERR of open!!!" << std::endl;
		in.close();
		out1.close();
		out2.close();
		if(inName != infile)
		{
			uFgen->delFile(inName);
		}
	}

	void FMan::merge2files()
	{
		std::ifstream in1("out1.tmp");
		std::ifstream in2("out2.tmp");
		std::ofstream out("sortOut.tmp");
		std::merge( std::istream_iterator<std::string>(in1)
				  , std::istream_iterator<std::string>()
				  , std::istream_iterator<std::string>(in2)
				  , std::istream_iterator<std::string>()
				  , std::ostream_iterator<std::string>(out,"\n")
				  );
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
