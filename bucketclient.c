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

int main()
{
char arr[100];
char ip[20];
int rval;
int rv;
int k,ss,count;
int sock;
int monitor =0;
char input[5],test[20],authen1[20];
char max[10];//usernamepr[20],passwordpr[20];
struct hostent *hp;
struct sockaddr_in client;
struct in_addr **addr_list;
int len;


if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
{
	perror("socket  creation failed");
	exit(-1);

}

client.sin_family = AF_INET;
client.sin_port = htons(21370);
hp = gethostbyname("localhost");

if(hp==0)
{
	perror("host name failed");
	close(sock);
	exit(-1);

}
memcpy(&client.sin_addr,hp->h_addr, hp->h_length);
//-----------------------ip part-----------------------------------------
addr_list = (struct in_addr **)hp->h_addr_list;
 inet_ntoa(*addr_list[0]);
strcpy(ip,inet_ntoa(*addr_list[0]));

//------------------------------------------------------------------------
//bzero(&server.sin_zero, 8);
//char *abc=(char *)hp->h_addr;
//printf("%s",inet_ntoa(client.sin_addr));

len = sizeof(struct sockaddr_in);

if((connect (sock, (struct sockaddr *)&client,len)) == -1)
{
	perror("socket  creation failed");
	exit(-1);
}

int local_port;
struct sockaddr_in some;
socklen_t addrlen = sizeof(some);
if(getsockname(sock, (struct sockaddr *)&some, &addrlen)==0 &&some.sin_family == AF_INET && addrlen == sizeof(some))
{local_port =ntohs(some.sin_port);}
 strcpy(authen1,"send");
//--------------------------------------------------sending authentication details---------------------------------------
send(sock, authen1, strlen(authen1), 0);

memset(arr,0,sizeof arr); // setting buffer to zero

printf("Low power level indicated to the VPP\n");
        
	
//--------------------------------------------------------------------------------------------------------------------------
	
//--------------------------------------------------check if authentication was successful or not---------------------------------------
strcpy(test, "success");
int ii=0,count1=0,teg=0;
//while(ii<20)
while(count1<100)
{

memset(arr,0,sizeof arr);
if ((rval = recv(sock,arr,sizeof arr,0)) < 0) 
	{
			perror("Cannot receive");

	}
	//printf("%s\n",arr);
	if(strcmp(arr,test)==0)
		{
		printf("Phase 1 :VPP DID NOT SEND\n");
		exit(0);
		}

//else if (strcmp(arr,test) == 0)
else		{
		//printf("%s\n",arr);
		teg=atoi(arr);	
		count1=count1+teg;
		if(count1>100) 
		count1=100;
		printf("Accumulated charge is %d\n",count1);
		//send(sock,"Available", 9, 0);

		}
sleep(1);
//printf("Phase 1 :End of Phase 1 for Patient 1\n");
//ii=ii+1;
}
printf("\n");
printf("\n");
printf("*************************\n");
printf(" Bucket is fully charged\n");
printf("*************************\n");
//-----------------------------------end phase 3 udp part--------------------------------------------------------
return(0);

}
