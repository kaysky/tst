#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

const int N = 32;


struct id_info
{
	int nsfd;
};

void cli_handler(id_info id)
{
	int cn;
	int number;

	while(true)
	{
		cn = recv(id.nsfd,(void*)&number,sizeof(number),0);
		number *= 2;
		send(id.nsfd,(void*)&number,sizeof(number),0);
	}
}


int main(int argc, char* argv[])
{
	vector<thread> handlers;
	int sfd,nsfd;
	socklen_t caddrlen;
	struct sockaddr_in caddr,saddr; //Structs for Client and server Address in the Internet 

	sfd = socket(AF_INET,SOCK_STREAM,0);
	memset(&saddr,0,sizeof(saddr)); //Clear the Server address structure

	saddr.sin_family = AF_INET; //Internet Address Family
	saddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	saddr.sin_port = htons(5555);

	bind(sfd, (struct sockaddr*) &saddr,sizeof(saddr));
	listen(sfd,1);

	for(; ;)
	{
		caddrlen = sizeof(caddr);
		nsfd = accept(sfd,(struct sockaddr*) &caddr,&caddrlen);
		handlers.push_back(thread(cli_handler, id_info{nsfd}));
	}

	for(auto& e :handlers)
	{
		e.join();
	}

	close(nsfd);
	exit(0);
}
