#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "task.h"
#include "cJSON.h"

static struct tasks_info *tasks;

void send_json() {
    cJSON *infos;
    cJSON *info;
    int num;
    int i ;
    char temp[16];
    char *str;
    cJSON *root = cJSON_CreateObject();
    if (root == NULL){
        goto end;
    }

    num = tasks->num;
    cJSON_AddItemToObject(root, "num", cJSON_CreateNumber(num));

    infos = cJSON_CreateArray();
    if (infos == NULL) {
        goto end;
    }
    cJSON_AddItemToObject(root, "data", infos);

    for (i = 0; i < num; ++i) {
        info = cJSON_CreateObject();
        if (info == NULL) {
            goto end;
        }
        cJSON_AddItemToArray(infos, info);

        cJSON_AddItemToObject(info, "label", cJSON_CreateString(tasks->data[i].label));
        snprintf(temp, sizeof(temp), "%.2f", tasks->data[i].temp);
        cJSON_AddItemToObject(info, "temp", cJSON_CreateString(temp));
    }

    str = cJSON_Print(root);
    printf("%s", str);
    free(str);
end:
    cJSON_Delete(root);
    return ;
}

int main() {
    printf("Content-Type: text/html;charset=utf-8\r\n");
    printf("\r\n");

    tasks = (struct tasks_info *)init_shm();
    if (tasks == NULL) {
        printf("%s\n", "jon错误");
        return -1;
    }

    send_json();
    return 0;
}
