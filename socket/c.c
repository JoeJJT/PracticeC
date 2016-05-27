#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int sockfd;
	struct sockaddr_in client;
	char rxBuf[128];
	char rxBuf2[128];
	char txBuf[10] = "clientack";
	
	printf("Client Start...\n");
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	printf("Socketfd: %d\n",sockfd);	
	bzero(&client,sizeof(client));
	client.sin_family = AF_INET;
	client.sin_port = htons(5000);
	client.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	connect(sockfd, (struct sockaddr*)&client,sizeof(client));
	memset(rxBuf, '0',sizeof(rxBuf));
	int res = recv(sockfd,rxBuf,sizeof(rxBuf), 0);
	printf("receive from server: %s,%d bytes\n",rxBuf,res);
	send(sockfd,txBuf,sizeof(txBuf),0);
	/*
	while(1) {
		memset(&buffer, '0',sizeof(buffer));
		scanf("%s",&buffer);
		send(sockfd,buffer,sizeof(buffer), 0);

		close(sockfd);
	}*/
	close(sockfd);
	return 0;
}
