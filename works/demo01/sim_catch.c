//
// Created by FL on 2020/6/17.
//
//共享内存的创建
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "task.h"

static struct tasks_info *tasks;  //static:只在本文件内有效
static char* task_lables[] = {"机房1","机房2","机房3","机房4","机房5"};

//完成采集器工作，也就是写端
//参数num 就是产生多少组数据
void get_data(int num){
    //给第几条数据写信息
    tasks->num = num;
    int i;

    //分别给每条数据写入信息
    for(i = 0; i < num ; ++i) {
        tasks->data[i].temp = ((rand() % 9000) + 1000) / 100.0;
        snprintf(tasks->data[i].lable, "%s", (char*)task_lables[i]);
    }
}

void show_data(){
    int i;
    for(i = 0 ;i < tasks->num; ++i){
        printf("the lable is :%s ,the temp is %.2f\n",tasks->data[i].lable,tasks->data[i].temp);
    }
}

int main(){
    //随机数处理
    srand(time(NULL));
    //获取映射的共享内存的首地址
    tasks = (struct tasks_info *)init_shm();
    if(tasks == NULL){
        fprintf(stderr,"init share memory\n");
        return -1;
    }

    //定时，两秒钟获取一次数据,也可以说是刷新
    while(1){
        //随机给哪条数据添加信息
        //即采集是随机的
        get_data(rand()%5+1);
        show_data();
        sleep(2);
    }

    return 0;
}

