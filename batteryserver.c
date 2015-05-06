#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<errno.h>
#include	<string.h>
#include	<netdb.h>
#include	<sys/types.h>
#include	<netinet/in.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	<sys/wait.h>
#include        <fcntl.h>


int main()

{

int sock, child;
struct sockaddr_in server;
struct sockaddr_in their_addr;
socklen_t addr_size;
int len;
int count =0;
char arr[1024],port111[20];
//char *host="nunki.usc.edu";
char strtest[1024],ipclient[50];
char max[10];
int rval;
//---------------------------------------------------------create socket and initialize the structures------------------------------------------------------------------
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket  creation failed");
		exit(-1);

	}

server.sin_family = AF_INET;
server.sin_port = htons(21370);
server.sin_addr.s_addr = inet_addr("127.0.0.1");
//bzero(&server.sin_zero, 8);

len = sizeof(struct sockaddr_in);
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

strcpy(strtest,"send");
//--------------------------------------------------------------bind the socket------------------------------------------------------------------------------------------
	if((bind (sock, (struct sockaddr *)&server,len)) == -1)
		{
			perror("socket  creation failed");
			exit(-1);
		}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------Listen for client connections------------------------------------------------------------------------------------------------------

listen(sock, 5);
printf("\n");
printf("\n");
printf("The VPP is now ON and ready to distribute power\n");
printf("\n");
int sendcount=0;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int randomNum;
char send[100];
//---------------------------------------------------------------------Infinite while loop for always ON server--------------------------------------------------------------
while(1)
{

	if((child = accept(sock, (struct sockaddr *)&their_addr, &len))== -1)

		{ 
			perror("socket  creation failed");
			exit(-1);
		}
	else {  //socket accept suuceesful 
		      
				
				
				memset(arr,0,sizeof arr); //authentication request receive
				if ((rval = recv(child,arr,sizeof arr,0)) < 0) 
					{
				perror("Cannot send");
					}
				arr[rval]='\0';
				
				strcpy(strtest, arr);
		if(strcmp(arr, strtest) == 0) //-----comapring string authenticate patient1 password111, with received string------------------------------------------------------------
			{	printf("\n");
				printf("Battery needs charging at constant rate of 5 percent/sec \n");	
				fflush(stdout);
				//for(sendcount=0;sendcount<=20;sendcount++)
				while(sendcount<20)				
				{
				//randomNum = rand() % 10 + (-9);
				//randomNum = rand() % 10;
				randomNum=5;
				sendcount=sendcount+1;
				printf("Power generated at constant rate : %d percent of total capacity\n",randomNum);
				sprintf(send, "%d", randomNum);
				sendto(child, send, strlen(send), 0,(struct sockaddr *)&their_addr,sizeof(their_addr));
				//printf(" trial no %d \n ",sendcount);	
				fflush(stdout);
				sleep(2);
				}
				
								
			}
		
		
		
}



}
close(child);
return(0);

}
