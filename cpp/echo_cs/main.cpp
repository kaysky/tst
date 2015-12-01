#include <iostream>
#include <cstdio>

using namespace std;

unsigned short x = 1; /*  0x0001 */

int main(int argc, char *argv[])
{
	std::cout << "test ECHO client/server app" << std::endl;


	printf("%s\n", *((unsigned char *) &x) == 0 ? "big-endian" : "little-endian");


	std::cout << "end of the test. " << std::endl;
	return 0;
}
