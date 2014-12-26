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
char buf[2048]="GET /Resized/17.gif?width=160,height=0 HTTP/1.1 \nUser-Agent: Dalvik/1.6.0 (Linux; U; Android 4.2.2; MiBOX1S Build/CADEV)\nHost: 192.168.31.1:8200\nConnection: Keep-Alive\nAccept-Encoding: gzip\r\n\r\n";
void fun(){
	printf("begin fun\n");
	int cfd;
	int recbytes;
	int sin_size;
	char buffer[1024]={0};   
	struct sockaddr_in s_add,c_add;
	unsigned short portnum=8888; 

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
	s_add.sin_addr.s_addr= inet_addr("192.168.31.1");
	s_add.sin_port=htons(portnum);


	if(-1 == connect(cfd,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))
	{
		    printf("connect fail !\r\n");
				    return -1;
	}
	printf("connect ok !\r\n");

  sleep(5);

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

/*
 *
 * [2014/03/24 16:52:20] upnphttp.c:854: debug: HTTP REQUEST: GET /MediaItems/71.png HTTP/1.1
 * User-Agent: Dalvik/1.6.0 (Linux; U; Android 4.2.2; MiBOX1S Build/CADEV)
 * Host: 192.168.31.1:8200
 * Connection: Keep-Alive
 * Accept-Encoding: gzip
 *
 */


	pthread_t thread1=0;
	pthread_t thread2=0;
	pthread_t thread3=0;
int main()
{
	printf("begin !!!\n");
	//pthread_t thread1=0;
	//pthread_t thread2=0;
	if(pthread_create(&thread1,NULL,fun,NULL)!=0){
		printf("create thread1 fail\n");
	}
/*
	if(pthread_create(&thread2,NULL,fun,NULL)!=0){
		printf("create thread2 fail\n");
	}

	if(pthread_create(&thread3,NULL,fun,NULL)!=0){
		printf("create thread3 fail\n");
	}*/
	printf("end !!!\n");
	while(1){
		sleep(1);
	}
	return 0;
}
