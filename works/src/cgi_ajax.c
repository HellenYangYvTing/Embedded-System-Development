#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cJSON.h"

// ajax获取jion格式
char *get_rand_temp(){
	cJSON *root;
	char *res = NULL;
	double temp;

	srand(time(NULL));
	temp = rand()%20 + 10;

	root = cJSON_CreateObject();
	if(root == NULL){
		goto end;
	}

	cJSON_AddItemToObject(root,"temp",cJSON_CreateNumber(temp));
	

	res = cJSON_Print(root);

	end:
		cJSON_Delete(root);
	return res;

}

int main()
{
	char *r1;

	printf("Content-Type:text/html;charset=utf-8\r\n");
	printf("\r\n");

	r1 = get_rand_temp();
	printf("%s",r1);
	free(r1);

	
	return 0;
}