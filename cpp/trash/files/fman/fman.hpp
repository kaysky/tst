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

	void testCopyFile();
	void sort_case(way );
	void direct_sort();
	void show_free_mem();
	void split2tmp();
	void merge4tmp();
};



};
#endif /* __FMAN_HPP__ */
