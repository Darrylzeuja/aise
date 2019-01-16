#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main( int argc, char ** argv )
{
	struct addrinfo *res = NULL;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if(argc != 2)
		return 1;

	int ret = getaddrinfo(NULL, argv[1],
			&hints,
			&res);

	if( ret < 0)
	{
		herror("getaddrinfo");
		return 1;
	}

	struct addrinfo *tmp;
	int listen_sock = -1;
	int binded = 0;
	
	for (tmp = res; tmp != NULL; tmp = tmp->ai_next) {
		listen_sock = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);

		if( listen_sock < 0) {
			perror("sock");
			continue;
		}

		ret = bind( listen_sock, tmp->ai_addr, tmp->ai_addrlen);

		if( ret < 0 ) {
			close(listen_sock);
			perror("bind");
			continue;
		}
		binded = 1;
		break;
	}

	if(!binded)
	{
		fprintf(stderr, "Failed to bind on 0.0.0.0:%s\n", argv[1]);
		return 1;	
	}

	/* Start listening */
	ret = listen(listen_sock, 2);

	if( ret < 0)
	{
		perror("listen");
		return 1;
	}


	/* Now accept one connection */
	struct sockaddr client_info;
	socklen_t addr_len;
	fprintf(stderr,"Before accept\n");
	int client_socket = accept(listen_sock, &client_info, &addr_len);
	fprintf(stderr,"After accept\n");

	if( client_socket < 0)
	{
		perror("accept");
		return 1;
	}

	fprintf(stderr,"Closing client socket\n");
	close(client_socket);


	close(listen_sock);

	return 0;
}
