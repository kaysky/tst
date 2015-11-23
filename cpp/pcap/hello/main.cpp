#include <pcap.h>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	std::cout << "tets pcap lib ..." << std::endl;


	char *dev, errbuf[PCAP_ERRBUF_SIZE];

	dev = pcap_lookupdev(errbuf);
	if (dev == NULL)
	{
		cout << "Couldn't find default device: " <<  errbuf << endl;;
		return(2);
	}
	std::cout << "hello my sniff device :" << dev << std::endl;

	std::cout << "end of the test." << std::endl;
	return 0;
}
