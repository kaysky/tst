#ifndef __HELPERS__HPP__

#define __HELPERS__HPP__

#include "somelib.hpp"

namespace kki
{

void show_usage(char *arg[]);

bool parse_cmd(int argc, char *arg[], std::vector<std::string> &cmd_line);


}

#endif /*__HELPERS__HPP__ */
