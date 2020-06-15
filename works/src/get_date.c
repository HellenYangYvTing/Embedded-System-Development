#include <stdio.h>
#include "stdlib.h"
#include "cJSON.h"

int main()
{
	cJSON *root;
	char *res;

	root = cJSON_CreateObject();
	if(root == NULL){
		goto end;
	}

	cJSON_AddItemToObject(root,"1",cJSON_CreateString("hello World"));
	cJSON_AddItemToObject(root,"2",cJSON_CreateString("haiwang"));

	res = cJSON_Print(root);
	printf("The results is :\n%s\n", res);
	free(res);

	end:
		cJSON_Delete(root);

	return 0;
}