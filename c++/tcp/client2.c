/*************************************************************************
    > File Name: client.c
    > Author: 刘铁俊
    > Mail: liutiejun@xiaomi.com
    > Created Time: 2014年03月21日 星期五 13时53分30秒
 ************************************************************************/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
int main(){	
printf("begin fun\n");
	char buf[]="this is buf";
  int cfd;
	int recbytes;
	int sin_size;
	char buffer[1024]={0};   
	struct sockaddr_in s_add,c_add;
	unsigned short portnum=0x8888; 

	printf("Hello,welcome to client !\r\n");

	cfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == cfd)
	{
		    printf("socket fail ! \r\n");
				    return -1;
	}
	printf("socket ok !\r\n");

	bzero(&s_add,sizeof(struct sockaddr_in));
	s_add.sin_family=AF_INET;
	s_add.sin_addr.s_addr= inet_addr("127.0.0.1");
	s_add.sin_port=htons(portnum);


	if(-1 == connect(cfd,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))
	{
		    printf("connect fail !\r\n");
				    return -1;
	}
	printf("connect ok !\r\n");

  sleep(15);

  if(-1==write(cfd, buf, 2048)){
		printf("write fail\n");
		return -1;
	}

	printf("write ok !\r\n");

	if(-1 == (recbytes = read(cfd,buffer,1024)))
	{
		    printf("read data fail !\r\n");
				    return -1;
	}
	printf("read ok\r\nREC:\r\n");

	buffer[recbytes]='\0';
	printf("%s\r\n",buffer);

	getchar();
	close(cfd);
	return;
}

