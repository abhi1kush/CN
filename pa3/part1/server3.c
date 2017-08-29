#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 256
#define MAX_NO_OF_THREAD 100

void comm(int newsockfd);


int main(int argc, char *argv[])
{
	    int sockfd,portnum,n,client_addr_len,i=MAX_NO_OF_THREAD;
	  
	    struct sockaddr_in server_addr,client_addr;
	    char inputbuf[MAX_INPUT_SIZE];
   	    
	    pthread_attr_t detach; /*attribute for detachable threads */
	    
	    n=pthread_attr_init(&detach);
	    if(n!=0)
	    
	    {
		fprintf(stderr,"ERROR to initialzing attribue");
		exit(1);
	    }
	    
	    n=pthread_attr_setdetachstate(&detach,PTHREAD_CREATE_DETACHED); /*setting detach state*/
	    if(n!=0)
	    {
		fprintf(stderr,"ERROR in make detachable thread");
		exit(1);
	    }
	     
	   
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
		      server_addr.sin_addr.s_addr= inet_addr("192.168.6.41");
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
                    int newsockfd;
		    pthread_t tid;
		     /* Accept at server */
	            client_addr_len=sizeof(client_addr);
	            newsockfd= accept(sockfd,(struct sockaddr *) &client_addr,&client_addr_len);
		    if (newsockfd < 0)
		  	    {
				  fprintf(stderr, "ERROR accepting to socket\n");
				  exit(1);
                                  
			    }
			     printf("connected with client no %d: \n",newsockfd);
			    
		
		    
	      	     
		    pthread_create(&tid,&detach,comm,newsockfd); /*creating a thread to handle multiple clients*/
		      
                      			     
                }while(1);
		
		return 0;
}


void comm(int newsockfd)
{
     char inputbuf[MAX_INPUT_SIZE];
     int n;
     do
	  {
		/* Reading message at server */
		bzero(inputbuf,MAX_INPUT_SIZE);
		n = read(newsockfd,inputbuf,MAX_INPUT_SIZE);
		if(n==0)// socket is already disconnected
		{
						
			close(newsockfd);
			fprintf(stderr, "ERROR reading to socket %d\n",newsockfd);
			return 0;
		}
		else if (n < 0)
		  {
		    fprintf(stderr, "ERROR reading to socket\n");
		     return 0;   
		  }
		if(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'))
		   printf("\nClient socket %dsent msg: %s",newsockfd,inputbuf);
		else
		   printf("\n Client socket %d said %s: finishing\n ",newsockfd,inputbuf);

		/* Write to client */
	       if(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'))
		{
			n = write(newsockfd,"OK Abhishek Singh",strlen("OK Abhishek Singh"));
			if (n < 0)
			  {	
			    close(newsockfd); // socket is already disconnected
			    fprintf(stderr, "ERROR writing to socket\n");
			    return 0;
			  }
		    }
		else
		{
			n = write(newsockfd,"Goodbye Abhiskek singh",strlen("Goodbye Abhiskek singh"));
                        if (n < 0)
			  {  close(newsockfd);
			    fprintf(stderr, "ERROR writing to socket\n");
			     return 0;
			  }
		}
		printf("Replied to client %d:\n",newsockfd);
               

	      } while(!((inputbuf[0] == 'B'||inputbuf[0] == 'b') && inputbuf[1] == 'y' && inputbuf[2] == 'e'&& inputbuf[3] == '\n'));
			      
	      n= close(newsockfd);
	      if(n<0)
   	      { printf("ERROR in closing socket");}
		     

		        


}



           
