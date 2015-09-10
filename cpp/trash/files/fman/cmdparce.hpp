#ifndef __HELPERS__HPP__

#define __HELPERS__HPP__

#include "fman.hpp"

namespace kki
{


class cmd
{
	static const int Mb = 1000000;	// 1 Mb const
	static const int dflim = 8000;	//default limit
	/*
	 *	cmd_line keeps input parameters of aplication
	 */
	std::vector<std::string> cmd_line;

	/*
	 *	inFileName is a name of input file to sort
	 */
	std::string inFileName;

	/*
	 *	outFileName is a name of sorted output file
	 */
	std::string outFileName;

	/*
	 * 	mem_size defines the volume of available RAM for sorting algorithm
	 * 	NOTE: may not be bigger then max size of available RAM in the system
	 */
	ULL_int mem_limit;

public:

	/*
	 *	show_usage prints help of aplication
	*/
	void show_usage(char *arg[]);

	/*
	 *	parce_cmd inits cmd_line based on user's input params
	 *	argc - a number of parameters
	 *	arg - an array of values of the parameters
	 *	NOTE: parameters has strict order
	 */
	bool parse_cmd(int argc, char *arg[]);

	void show_cmd_line();
	const std::string& get_fin() const { return inFileName; }
	const std::string& get_fout() const { return outFileName; }
	ULL_int get_limit() const { return mem_limit * Mb; }

};


};

#endif /*__HELPERS__HPP__ */
