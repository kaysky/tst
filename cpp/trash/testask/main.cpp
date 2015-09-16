/* 
 *			That is a test task
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;


/* 
 *	f-n somehow takes a list of test hashes
 *	in my case that is a data file
 */
void get_hash(vector<string> &vh)
{
	ifstream in("rep");
	if(in.is_open())
	{
		copy( istream_iterator<string>(in)
			, istream_iterator<string>()
			, back_inserter(vh)
			);
	}
}


/* 
 *	f-n checkes list of the hashes
 */
bool isTestsSuccess(const string &str)
{
	//main condition to find out what is wrong with test suit
	if(str.find("d9") != string::npos)
		return false;
	else
		return true;
}


int main(int argc, char *argv[])
{
	std::cout << "test task :" << std::endl << std::endl;

	vector<string> hashes;

	get_hash(hashes);

	for(const auto& e :hashes)
	{
		if(!isTestsSuccess(e))
		{
			std::cout << "test case for " << e << " :False" << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "end of the test task." << std::endl;
	return 0;
}

/* 
 *
 * This algorithm has linear complexity [O(n)] because it uses isTestSuccess() 
 * check for every hash element.
 *
 * OUTPUT:
				  test task :
				  test case for 6b9483d9 :False
				  end of the test task.
 *
 *
 *
 *
 * */
