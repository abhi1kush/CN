#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>


#define MAX_INPUT_SIZE 256
int communication(char* inputbuf,int newsockfd);

int main(int argc, char *argv[])
{
   pid_t pid;
	
  
	    int sockfd, newsockfd,portnum,n,client_addr_len;
	    struct sockaddr_in server_addr,client_addr;
	    char inputbuf[MAX_INPUT_SIZE];
            if (argc < 2)
	    {
		       fprintf(stderr,"usage %s <server-port>\n", argv[0]);
		       exit(0);
            }

	    portnum = atoi(argv[1]);

		    /* Create server socket */
		    sockfd = socket(AF_INET, SOCK_STREAM, 0);
		    if (sockfd < 0)
		      {
			fprintf(stderr, "ERROR opening socket\n");
			exit(1);
		       }
		      bzero((char *)&server_addr,sizeof(server_addr));
		      server_addr.sin_family= AF_INET;
		      server_addr.sin_addr.s_addr= inet_addr("127.0.0.1");
		      server_addr.sin_port= htons(portnum);

		    /*Bind socket */
		    if(bind(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr))<0)
		     {
		       fprintf(stderr,"ERROR in binding socket \n ");
		       exit(1);
		     }


		    /*Listen */
                    listen(sockfd,10);


	            
	          
	      
                 do{
		     /* Accept at server */
	            client_addr_len=sizeof(client_addr);
	            newsockfd= accept(sockfd,(struct sockaddr *) &client_addr,&client_addr_len);
		    if (newsockfd < 0)
		  	    {
				  fprintf(stderr, "ERROR accepting to socket\n");
				  exit(1);
                                  
			    }
		     printf("connected with client no %d: \n",newsockfd);
		     
      		
		     if(pid=fork()>0) /* at parent process*/
                      {
			  close(newsockfd);
			
			  
                      }
                      else if(pid==0) /*at child process*/
                      {   
			     char inputbuf[MAX_INPUT_SIZE];
		             do
			      {
				/* Reading message at server */

				bzero(inputbuf,MAX_INPUT_SIZE);
				n = read(newsockfd,inputbuf,MAX_INPUT_SIZE);
				if (n < 0)
				  {
				    fprintf(stderr, "ERROR reading to socket\n");
				     exit(1);
                                     
				  }

				if(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'))
				   printf("\nClient socket %d sent msg: %s",newsockfd,inputbuf);
				else
				   printf("\n Client socket %d said %s: finishing\n ",newsockfd,inputbuf);



				/* Write to client */

			       if(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'))
				{

					n = write(newsockfd,"OK Abhishek Singh",strlen("OK Abhishek Singh"));
					if (n < 0)
					  {
					    fprintf(stderr, "ERROR writing to socket\n");
					    exit(1);
					  }
				    }
				else
				{
					n = write(newsockfd,"Goodbye Abhiskek singh",strlen("Goodbye Abhiskek singh"));
                                        if (n < 0)
					  {
					    fprintf(stderr, "ERROR writing to socket\n");
					     exit(1);
					  }
				}
				printf("Replied to client %d:\n",newsockfd);
                           

			      } while(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'));
				      
			      n= close(newsockfd);
			      if(n!=0)
		   	      { printf("ERROR in closing socket");}
			      pid=getpid();
			      kill(pid,SIGKILL); /*killing child process*/
			      break;

		        }
			else if(pid==-1)
				{
					close(newsockfd);
					printf("Failed to create child process");
				}
                                    
                                         
                }while(1);

		n= close(sockfd);
		if(n<0)
	   	{ printf("ERROR in closing socket");}
		return 0;
}



           
