#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main( int argc, char ** argv )
{
	struct addrinfo *res = NULL;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	int ret = getaddrinfo(argv[1], argv[2],
			&hints,
			&res);

	if( ret < 0)
	{
		herror("getaddrinfo");
		return 1;
	}

	struct addrinfo *tmp;
	int sock = -1;
	int connected = 0;
	for (tmp = res; tmp != NULL; tmp = tmp->ai_next) {
		sock = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);

		if( sock < 0) {
			perror("sock");
			continue;
		}

		int ret = connect( sock, tmp->ai_addr, tmp->ai_addrlen);

		if( ret < 0 ) {
			close(sock);
			perror("connect");
			continue;
		}
		connected = 1;
		break;
	}

	if(!connected)
	{
		fprintf(stderr, "Failed to connect to %s:%s\n",argv[1], argv[2]);
		return 1;	
	}

	/* Use the socket */
	char buff[500];

	/* Read from sock */
	while(1)
	{
		ssize_t ret = read(sock, buff, 500);

		if( ret == -1 )
		{
			if(errno == EINTR)
				continue;
			else
			{
				perror("read");
				break;
			}
		}

		if( ret == 0)
			break;


		write(STDOUT_FILENO, buff, ret);
	}


	close(sock);

	return 0;
}
