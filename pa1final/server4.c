
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<sys/select.h>


#define MAX_INPUT_SIZE 256





int main(int argc, char *argv[])
{
	
	int listen_sockfd,portnum,n,client_addr_len,i,fdmax,clientfd;
	  
	struct sockaddr_in server_addr,client_addr;
	char inputbuf[MAX_INPUT_SIZE];
	
	fd_set master_fds;
	fd_set read_fds;
	
	     
	if (argc < 2)
	{
	    fprintf(stderr,"usage %s <server-port>\n", argv[0]);
	    exit(0);
	}

	portnum = atoi(argv[1]);
	
	/* Create server socket */
	listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sockfd < 0)
	{
		fprintf(stderr, "ERROR opening socket\n");
		exit(1);
	}
	
	
	
	bzero((char *)&server_addr,sizeof(server_addr));
	server_addr.sin_family= AF_INET;
	server_addr.sin_addr.s_addr= inet_addr("127.0.0.1");
	server_addr.sin_port= htons(portnum);

	/*Bind socket */
	if(bind(listen_sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
	    fprintf(stderr,"ERROR in binding socket \n ");
	    exit(1);
	}


	/*Listen */
    	listen(listen_sockfd,10);
	
	FD_ZERO(&master_fds);
	FD_SET(listen_sockfd,&master_fds);
	fdmax = listen_sockfd;

	printf("strating select loop  fdmax :%d\n",fdmax);
	for(; ;)
	{   		
			//giving list of socket to check
			read_fds = master_fds;

			n = select(fdmax+1,&read_fds,NULL,NULL,NULL);
			
			 if (n < 0)
			  {
			    fprintf(stderr, "SELECT sys call error\n");
			     exit(1);
		                        
			  }
			
			
			for(i=0;i<=fdmax;i++)
			{	
				
				if(FD_ISSET(i,&read_fds) && (i==listen_sockfd)) /* checking is it "listen_sockfd" main socket to listen reqst*/ 
				{
					printf("In select loop: socket %d is ready to read\n",i);				    	
					client_addr_len=sizeof(client_addr);
					/* Accept at server */
					clientfd= accept(listen_sockfd,(struct sockaddr *) &client_addr,&client_addr_len);
					if (clientfd < 0)
					{	
						
						fprintf(stderr, "ERROR accepting to socket\n");
						
								  
					}
					else
					{
					
					FD_SET(clientfd, &master_fds);
								  
					if(clientfd > fdmax)
						fdmax = clientfd;
			
					printf("connected with client socket %d: \n",clientfd);
					}
				
				}
				else if(FD_ISSET(i,&read_fds))
				{
					printf("In select loop: socket %d is ready to read\n",i);			
					clientfd=i;
					

					/* Reading message at server */
					bzero(inputbuf,MAX_INPUT_SIZE);
					n = read(clientfd,inputbuf,MAX_INPUT_SIZE);
					if(n==0)// socket is already disconnected
					{
						FD_CLR(i,&master_fds);
						close(clientfd);
						fprintf(stderr, "ERROR reading to socket %d\n",i);
						continue;
					}
					else if (n < 0)
					{
					    fprintf(stderr, "ERROR reading to socket %d\n",i);
					     
						        
					}
					
					
					if(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'))
					   printf("\nClient  socket %d sent msg: %s",clientfd,inputbuf);
					else
					   printf("\n Client %d said %s: finishing\n ",clientfd,inputbuf);

					/* Write to client */
					if(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'))
					{
						n = write(clientfd,"OK Abhishek Singh",strlen("OK Abhishek Singh"));
						if (n < 0)
						{   
						    FD_CLR(i,&master_fds);  // socket is already disconnected
						     close(clientfd);
						    fprintf(stderr, "ERROR writing to socket %d\n",i);
						    continue;
						    
						}
					}
					else
					{
						n = write(clientfd,"Goodbye Abhiskek singh",strlen("Goodbye Abhiskek singh"));
						if (n < 0)
						  {	
						     FD_CLR(i,&master_fds);  // socket is already disconnected
						     close(clientfd);
						     fprintf(stderr, "ERROR writing to socket %d\n",i);
						     continue;
						     
						  }
					}
		
					printf("Replied to client %d:\n",clientfd);
					
					


					if(((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'))
					{
						n= close(clientfd);
						if(n<0)
				   	        printf("ERROR in closing socket\n");
						FD_CLR(i,&master_fds);
					 }     
					 
				
				 }
			}
	}
	return 0;

}



    		




           
