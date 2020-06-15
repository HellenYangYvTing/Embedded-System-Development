#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *res;
	char *query_str;
	int num;
	int i;
	int flags = 0;//默认0位get请求

	printf("Content-Type:text/html;charset=utf-8\r\n");
	printf("\r\n");

	res = getenv("REQUEST_METHOD");
	if(res == NULL){
		printf("获取method失败！");
		return 0;
	}
	printf("<h2> form测试的http请求形式：%s\n", res);

	if(strncmp(res,"GET",3) == 0){
		query_str = getenv("QUERY_STRING");
		if(query_str == NULL){
			printf("获取query string失败！");
			return 0;
		}
		
	}
	else if(strncmp(res,"POST",4) == 0){
		 num = atoi(getenv("CONTENT_LENGTH"));
		 flags = 1;
		 query_str = (char *)malloc(num + 1);
		 for(i = 0; i < num; ++i ){
		 	query_str[i] = fgetc(stdin);
		 }
		 query_str[i] = 0;
		
	}
	else{
		printf("<h3>form请求类型未知</h3>\n" );

	}
		printf("<h3> form测试的%s请求数据：%s\n", res,query_str);

	if(flags){
		free(query_str);
	}

	return 0;
}