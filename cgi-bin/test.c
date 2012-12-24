#include <stdio.h>
#include "cgic/cgic.h"

int cgiMain()
{

	cgiHeaderContentType("text/html;charset=gb2312");
	char name[1024]="";
	cgiFormString("phone", name, 1024);
	//printf("<HTML><HEAD>\n");
	//printf("<TITLE>NS-100-CRx Web Server</TITLE></HEAD>\n");
	printf("%s", name);
	//printf("</BODY>\n");
	//printf("</HTML>\n");

	return 1;
}
