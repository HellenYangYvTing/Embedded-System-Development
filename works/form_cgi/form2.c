#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgic.h"

int cgiMain()
{
	char user[16];
	char pwd[16];
	char *method;

	cgiHeaderContentType("text/html;charset=utf-8");

	cgiFormStringNoNewlines("user_name",user,16);
	cgiFormStringNoNewlines("user_pwd",pwd,16);

	method = getenv("REQUEST_METHOD");

	fprintf(cgiOut, "<h3>form测试的%s请求数据：%s ,%s\n</h3>", method,user,pwd);

	return 0;
}