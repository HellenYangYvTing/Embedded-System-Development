#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "task.h"

void* init_shm(void) {
    key_t k1;
  //  key_t semkey;
    int shm_id;
    void *res;

    //printf("%s\n", "-----------------");

   /*  if((semkey = ftok("./home", 1))<0)  
        {  
            printf("ftok failed\n");  
            exit(EXIT_FAILURE);  
        }     
        printf("ftok ok ,semkey = %d\n", semkey);  
*/

    k1 = ftok("./home", 10);
     //printf("ftok:%d\n",k1 );
    if ( k1 == -1 ) {
        return NULL;
    }

    shm_id = shmget(k1, sizeof(struct tasks_info), IPC_CREAT | 0644);
    // printf("shm_id:%d\n",shm_id );
    if ( shm_id == -1 ) {
        return NULL;
    }

    res = shmat(shm_id, NULL, 0);
    //printf("+++++++++==");

    return res;
}

void detach_shm(void *p) {
    shmdt(p);
}
