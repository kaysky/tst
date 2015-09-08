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

namespace kki
{

	typedef std::list<std::string> FileNames;
	typedef std::multiset<std::string> RAMBuff;


class TempFileGenerator
{
	FileNames fnames;
	TempFileGenerator(const TempFileGenerator&){}
public:
	TempFileGenerator() {}
	~TempFileGenerator() {}
	void addFile(const std::string &, RAMBuff &);
	FileNames& getFlist() { return fnames;  }
	void delFlist();
};


class FMan
{
	std::unique_ptr<TempFileGenerator> uFgen;
	std::string infile;
	std::string outfile;
	enum way {direct,split};
public:
	RAMBuff buff;
	FMan(std::string fin, std::string fout)
		: uFgen(new TempFileGenerator)
		, infile(fin)
		, outfile(fout)
	{}
	~FMan() {}

	void sort_case(way );
	void direct_sort();
	void indirect_sort();
	unsigned int detect_free_ram();
	unsigned int detect_file_size();
	void split2tmp();
	void split2double();
	void in2out();
	void mergeTmpFiles();

	void testCopyFile();
	void merge2files();
};



};
#endif /* __FMAN_HPP__ */
