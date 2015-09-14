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

class mystring :public std::string
{
	friend std::istream& operator>>(std::istream &is, mystring &mystr)
	{
		return getline(is,mystr);
	}
};

	/*
	 * class defines methods to create and delete files
	 * and keeps list of these files
	 * fnames - list of created files
	 * obsolet_names - list of files' names for postpone deletion
	*/
class FileController
{
	FileNames fnames;
	FileNames obsolet_names;
	FileController(const FileController&){}
public:
	FileController() {}
	~FileController() {}

	/*
	 * f-n adds name to the list of files
	*/
	void addFileName(std::string &name) { fnames.push_back(name); }

	/*
	 * f-n returns the list of files
	*/
	FileNames& getFlist();

	/*
	 * f-n deletes particular file
	*/
	void delFile(const std::string&);
};

	/*
	 * File Manager (FMan)
	 * class defines main logic of operation with the sorted file
	 * I - direct, when file less then RAM and can be sorted in the RAM
	 * 	   and then write to HDD
	 * II- indirect, when file is too huge and can't be sorted in full
	 * 		aplication split the file into small backets till size acceprable
	 * 		for RAM and then sorted it, and then merge the files back into
	 * 		1 huge file
	 */
class FMan
{
	/* pointer to File controller */
	std::unique_ptr<FileController> uFgen;

	/* Name of input file defined by user
	 * NOTE: must be alwayse defined  and file must exist*/
	std::string infile;

	/* Name of output file is optional parameter */
	std::string outfile;

	/*
	 * Size of buffer for sorting
	 * parameter is optional for user defenition
	 * it is not a strict directive and has only recomendation meaning
	*/
	ULL_int user_ram_limitation;

public:

	/* Buffer for direct and indirect sorting
	 * a size depends on user's preference and max RAM size*/
	RAMBuff buff;

	FMan(std::string fin, std::string fout, ULL_int limit)
		: uFgen(new FileController)
		, infile(fin)
		, outfile(fout)
		, user_ram_limitation(limit)
	{}
	~FMan() {}

	/* starts sorting  */
	void proceed_sort();

	/* sorts temp files which meet size of Buff */
	void sort_tmp();

	/* f-n impliments Ist algorithm of sort */
	void direct_sort();

	/* f-n impliment IId algorithm of sort */
	void indirect_sort();

	/* f-n defines available RAM size
	 * NOTE: by default it allows to use 80% of available RAM size
	 */
	ULL_int detect_free_ram(float k = 0.8);

	/* f-n defines a size of a particular file */
	ULL_int detect_file_size(const std::string &name);

	/* f-n impliments algorithm of spliting one file to many smaller ones */
	void split2tmp();

	/* f-n impliment alg. of spliting one file to two files */
	void in2out(const std::string &, const std::string &);

	/* f-n merges all splited files in one */
	void mergeTmpFiles();

	/* f-n merges 2 files in 1 */
	void merge2files( const std::string&
					, const std::string&
					, std::string&
					);
};



};
#endif /* __FMAN_HPP__ */
