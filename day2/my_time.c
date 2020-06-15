#include <stdio.h>
#include <time.h>
#include <string.h>
#include "my_time.h"

char *get_time(time_t now)
{
	struct tm *local;
	static char buf[16]; //12:01:12
	
	if(now <= 0){
		now = time(NULL);
	}
	
	local = localtime(&now);
	if(local =NULL){
		perror("local time");
		return NULL;
	}
	
	snprintf(buf, sizeof(buf),"%02d:%02d:02d",
		local->tm_hour,local->tm_min,local->tm_sec);
	
	return buf;
}