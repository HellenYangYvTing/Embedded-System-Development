#ifndef WWW_TASK_H
#define WWW_TASK_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MAX_TASK 5

#define KEY_1 "/home"
#define KEY_2 10

//一条信息的内存
struct task_msg{
    double temp;
    char lable[32];
};

//5条信息的内存
struct tasks_info{
    int num;
    struct task_msg data[MAX_TASK];
};



//返回的是任意空间地址，也就是映射之后的共享内存的地址（真正还是在用户内存里）
extern void* init_shm(void);

//注销:注销的是映射的关系，而不是内核里的内存空间
extern void detach_shm(void *p);

#endif //WWW_TASK_H
