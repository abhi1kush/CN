#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<stdlib.h>
#include<string.h>
#define MAX_INPUT_SIZE 256

int main(int argc, char *argv[])
{
	int sockfd, portnum, n,connfd = 0,client_len;
	struct sockaddr_in server_addr,client_addr;
	char inputbuf[MAX_INPUT_SIZE];
	 
	if (argc < 3) 
	{
		fprintf(stderr,"usage %s  <server-port>\n", argv[0]);
		exit(0);
	}

	portnum = atoi(argv[2]);

    /* Create server socket */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
	{
		fprintf(stderr, "ERROR opening socket\n");
		exit(1);
	}

    /* Fill in server address */
	bzero((char *) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	 if(!inet_aton(argv[1], &server_addr.sin_addr))
      {
        fprintf(stderr, "ERROR invalid server IP address\n");
        exit(1);
      }
   	
//server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	server_addr.sin_port = htons(portnum);
	bind(sockfd, (struct sockaddr*)&server_addr,sizeof(server_addr));
  	listen(sockfd, 1);
	
	client_len=sizeof(client_addr);
	 /* Accept at server */
		
	printf("Server started...\nWaiting for client connection\n");		
	connfd = accept(sockfd, (struct sockaddr*)&client_addr,&client_len);
	close(sockfd);
	if(connfd<0)
	{
		fprintf(stderr,"Error connecting\n");
		exit(1);
	}
	
	printf("Connected with client socket no %d\n",connfd);
	
	do
	{
	/* Read reply */
		bzero(inputbuf,MAX_INPUT_SIZE);
		n = read(connfd,inputbuf,(MAX_INPUT_SIZE-1));
		if (n < 0) 
		{
			fprintf(stderr, "ERROR reading from socket\n");
			exit(1);
		}
		printf("Client socket %d replied: %s",connfd,inputbuf);
	

		/* Check that reply is either OK or Goodbye */
		if(inputbuf[0] == 'B' && inputbuf[1] == 'y'&& inputbuf[2] == 'e')
		{
			bzero(inputbuf,MAX_INPUT_SIZE);	
			strcpy(inputbuf, "Goodbye Gaurav");
			write(connfd, inputbuf, strlen(inputbuf));
			printf("Client said bye; finishing\n");
			close(connfd);    
			sleep(1);
			exit(1);
		}
		else
		{
			bzero(inputbuf,MAX_INPUT_SIZE);	
			strcpy(inputbuf, "OK Gaurav");
			write(connfd, inputbuf, strlen(inputbuf));
			printf("Replied to client\n");
	 	      //close(connfd);    
			sleep(1);
		}
	}while(1);

    return 0;
}
