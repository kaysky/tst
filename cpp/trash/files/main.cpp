#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char *argv[])
{
	std::cout << "test streams" << std::endl;

	string sLine = "";
	ifstream infile;

	infile.open("temp.txt");

	while (!infile.eof())
	{
		getline(infile, sLine);
		cout << sLine << endl;
	}

	infile.close();
	cout << "Read file completed!!" << endl;


	std::cout << "end of the test." << std::endl;
	return 0;
}
