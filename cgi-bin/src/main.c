/*
 * main.c
 *
 *  Created on: 2012-12-24
 *      Author: xul
 */


#include <stdio.h>
#include "cgic/cgic.h"

const StrLen = 1024*1024;
char sendstr[StrLen]="";
char recvstr[StrLen]="";

int cgiMain()
{
	tcpClient("127.0.0.1", 8086);
	tcpInit();
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
    int fd;
    struct sockaddr_in	addr;
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
    addr.sin_addr.s_addr	= (ip);
    addr.sin_port		= htons(port);



    printf("it will connect to serv!ip is %s, port = %d\n", sys_ip2str_static(ip), port);

    if ( connect( fd, (const struct sockaddr *)&addr, sizeof(addr)) < 0 )
    {
        perror("connect timeout");
        close(fd);
        return -1;
    }

    printf(" connect to serv ok!\n");
    return fd;

}

