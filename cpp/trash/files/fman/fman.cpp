#include "fman.hpp"

namespace kki
{

//void FileController::addSortedFile(const std::string &fname, RAMBuff &rambuff)
//	{
//		std::ofstream out(fname);
//		if(out.is_open()) fnames.push_back(fname);
//		std::ostream_iterator<std::string> out_it (out,"\n");
//		std::copy (rambuff.begin(), rambuff.end(), out_it);
//		out.close();
//	}
//
	FileNames& FileController::getFlist()
	{
		if(!obsolet_names.empty())
		{
			for(const auto& e :obsolet_names)
			{
				fnames.remove(e);
			}
			obsolet_names.clear();
		}
		return fnames;
	}

	void FileController::delFile(const std::string & name)
	{
		std::remove(name.c_str());
		obsolet_names.push_back(name);
	}

	void FileController::delFlist()
	{
		for(const auto& e :getFlist())
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

	void FMan::sort_tmp()
	{
		std::ifstream in;
		std::ofstream out;
		std::string tmp("");
		buff.clear();

		//sort all tmp files
		for(const auto& e :uFgen->getFlist())
		{
			in.open(e);
			if(in.is_open())
			{
				while(!in.eof())
				{
					getline(in,tmp);
					buff.insert(tmp);
				}
			}
			in.close();

			out.open(e);
			if(out.is_open())
				if(!buff.empty())
					copy( buff.begin()
						, buff.end()
						, std::ostream_iterator<std::string>(out,"\n")
						);
			buff.clear();
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

	void FMan::merge2files( const std::string& inn1
						  , const std::string& inn2
						  , std::string& outt
						  )
	{
		std::ifstream in1(inn1);
		std::ifstream in2(inn2);
		std::ofstream out(outt);

		if(	in1.is_open()
			&& in2.is_open()
			&& out.is_open()
		  )
		{
			std::merge( std::istream_iterator<std::string>(in1)
					  , std::istream_iterator<std::string>()
					  , std::istream_iterator<std::string>(in2)
					  , std::istream_iterator<std::string>()
					  , std::ostream_iterator<std::string>(out,"\n")
					  );
		}
		uFgen->addFileName(outt);
		uFgen->delFile(inn1);
		uFgen->delFile(inn2);
		std::cout	<< "add/del1/del2 :"
					<< outt << "/"
					<< inn1 << "/"
					<< inn2  << std::endl;
	}

	void FMan::mergeTmpFiles()
	{
		int idx(0);
		std::string out_name("");
		auto it1 = uFgen->getFlist().begin();
		auto it2 = it1;
		auto it_end = uFgen->getFlist().end();

		for ( it1, ++it2
			; it2 != it_end
			; ++it1, ++it2
			)
		{
			++idx;
			out_name = "out" + std::to_string(idx) + ".tmp";
			merge2files(*it1,*it2,out_name);
			++it1;
			++it2;
		}
	}

};
