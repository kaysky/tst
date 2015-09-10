#ifndef __FMAN_HPP__

#define __FMAN_HPP__

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <iterator>
#include <set>
#include <memory>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <utility>
#include <stdexcept>

namespace kki
{

	typedef std::list<std::string> FileNames;
	typedef std::multiset<std::string> RAMBuff;
	typedef unsigned long long int ULL_int;

class FileController
{
	FileNames fnames;
	FileNames obsolet_names;
	FileController(const FileController&){}
public:
	FileController() {}
	~FileController() {}
//	void addSortedFile(const std::string &, RAMBuff &);
	void addFileName(std::string &name) { fnames.push_back(name); }
	FileNames& getFlist();
	void delFlist();
	void delFile(const std::string&);
};


class FMan
{
	std::unique_ptr<FileController> uFgen;
	std::string infile;
	std::string outfile;
	enum way {direct,split};
	ULL_int user_ram_limitation;
public:
	RAMBuff buff;
	FMan(std::string fin, std::string fout, ULL_int limit)
		: uFgen(new FileController)
		, infile(fin)
		, outfile(fout)
		, user_ram_limitation(limit)
	{}
	~FMan() {}

	void sort_case(way);
	void sort_tmp();
	void direct_sort();
	void indirect_sort();
	ULL_int detect_free_ram();
	ULL_int detect_file_size(const std::string &name);
	void split2tmp();
	void split2double();
	void in2out(const std::string &, const std::string &);
	void mergeTmpFiles();

	void testCopyFile();
	void merge2files( const std::string&
					, const std::string&
					, std::string&
					);
};



};
#endif /* __FMAN_HPP__ */
