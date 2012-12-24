/*
 * main.c
 *
 *  Created on: 2012-12-24
 *      Author: xul
 */

#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <stdio.h>
#include "cgic/cgic.h"

#define StrLen 1024*1024
char sendstr[StrLen]="";
char recvstr[StrLen]="";
int fd;
struct sockaddr_in	addr;

int tcpClient(char* ip, short int port);
int tcpClientConnect();
int tcpSend(char* str);
int tcpRecv(char* str);

int cgiMain()
{
	tcpClient("127.0.0.1", 8086);
	tcpClientConnect();

	cgiHeaderContentType("text/html;charset=gb2312");
	cgiFormString("phone", sendstr, StrLen);
	tcpSend(sendstr);

	if(tcpRecv(recvstr) != -1)
	{
		printf("%s", recvstr);
	}
	else
	{
		printf("error\n");
	}

	close(fd);

	return 1;
#if 0
	cgiHeaderContentType("text/html;charset=gb2312");
	char name[1024]="";
	cgiFormString("phone", name, 1024);
	//printf("<HTML><HEAD>\n");
	//printf("<TITLE>NS-100-CRx Web Server</TITLE></HEAD>\n");
	printf("%s", name);
	//printf("</BODY>\n");
	//printf("</HTML>\n");

	return 1;
#endif
}


int tcpClient(char* ip, short int port)
{


    fd = socket( AF_INET, SOCK_STREAM, 0 );

    if (fd < 0)
    {
        perror("socket");
        return fd;
    }

	int rcvlen = 1024*1024;
    int ret = setsockopt(fd, SOL_SOCKET, SO_RCVBUF, &rcvlen, sizeof(int));

    if (ret == -1)
    {
        perror("net_server_start: setsockopt()");
        return;
    }

    bzero(&addr, sizeof(addr));
    addr.sin_family		= AF_INET;
    addr.sin_addr.s_addr	= inet_addr(ip);
    addr.sin_port		= htons(port);




    return fd;

}


int tcpClientConnect()
{


    if ( connect( fd, (const struct sockaddr *)&addr, sizeof(addr)) < 0 )
    {
        perror("connect timeout");
        close(fd);
        return -1;
    }

    //printf(" connect to serv ok!\n");
    return 1;
}

int tcpSend(char* str)
{
	int ret = send(fd, str, strlen(str), 0);
	if (ret < 0)
	{
		perror("send");
	}
	return ret;
}

int tcpRecv(char* str)
{
	int ret = recv(fd, str, StrLen, 0);
	if(ret < 0)
	{
		perror("recv");
	}
	return ret;
}
