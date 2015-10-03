#include "cform.hpp"

#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>


#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

const int N = 1024;

int main(int argc, char* argv[])
{
	int number;
	int sfd;
	struct sockaddr_in saddr;

	memset(&saddr,0,sizeof(saddr));
	sfd = socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family = AF_INET;
	inet_pton(AF_INET,"127.0.0.1",&saddr.sin_addr);
	saddr.sin_port = htons(5004);

	connect(sfd,(struct sockaddr*) &saddr, sizeof(saddr));
	for(; ;)
	{
		this_thread::sleep_for (std::chrono::seconds(1));
		number = rand() % 100 + 1;
		send(sfd,(void*)&number,sizeof(number),0);
		std::cout << "send :" << number << std::endl;
		recv(sfd,(void*)&number,sizeof(number),0);
		std::cout << "got :" << number << std::endl;
	}
	exit(0);
}
