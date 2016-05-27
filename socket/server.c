#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 
    char rxBuf[1025];
	char txBuf[20] = "Hi client!";
    time_t ticks; 
	printf("Server Start...\n");
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Listenfd: %d\n",listenfd);

    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(rxBuf, '0', sizeof(rxBuf)); 
	//memset(txBuf, '0', sizeof(txBuf));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
	
    listen(listenfd, 20); 
    while(1)
    {
		struct sockaddr_in client_addr;
		int addrlen = sizeof(client_addr);
		connfd = accept(listenfd,(struct sockaddr*)&client_addr,&addrlen);
		printf("Connectfd: %d\n",connfd);	
		send(connfd, txBuf,sizeof(txBuf), 0);
		int res = recv(connfd,rxBuf,sizeof(rxBuf),0);		
		printf("%d\n",res);
		printf("receive from client: %s,%d bytes\n",rxBuf,res);

        close(connfd);
		printf("Waiting..\n");
        sleep(1);
     }
	close(listenfd);
	return 0;
}
