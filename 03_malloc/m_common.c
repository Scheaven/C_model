#ifndef _M_COMMON_H_
#define _M_COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include "m_common.h"
//#define AXISQUEUE_SIZE 50    //队列中元素个数最大限制
//#define AMQUEUE_SIZE 50    //队列中元素个数最大限制
//#define QUEUE_TYPE int    //    定义队列类型为int

#define MY_MALLOC_SIZE 4096
#define ARRAY_MALLOC_SIZE 212
#define LIST_MALLOC_SIZE 804
static int16_t g_malloc[MY_MALLOC_SIZE];
static int16_t am_array[ARRAY_MALLOC_SIZE];
static int16_t axis_array[ARRAY_MALLOC_SIZE];
static int16_t mean_array_list[LIST_MALLOC_SIZE];
static int16_t std_array_list[LIST_MALLOC_SIZE];
static int g_pos=0;

int16_t *m_malloc(int size)
{
    int pos;
    if(size<=0 || size > MY_MALLOC_SIZE)
    {
        printf("ERROR: para error.\n");
        return NULL;
    }

    if(g_pos+size > MY_MALLOC_SIZE)
    {
        printf("ERROR: no Memery.\n");
        return NULL;
    }

    pos = g_pos;
    g_pos += size;

    return &g_malloc[pos];
}


int16_t *new_queue(int size,char *name)
{
    if(strcmp(name, "am") == 0)
    {
        return &am_array[0];
    }else if(strcmp(name, "axis") == 0)
    {
        return &axis_array[0];
    } else if(strcmp(name, "mean") == 0)
    {
        // printf("%s\n","121212" );
        return &mean_array_list[0];
    }else if(strcmp(name,"std") == 0)
    {
        // printf("%s\n","33333" );
        return &std_array_list[0];
    }
}

int16_t *new_list(int size,char *name)
{
    // printf("%d\n", size);
    if(strcmp(name, "mean") == 0){
        // printf("%s\n","121212" );
        return &mean_array_list[0];
    }else if(strcmp(name,"std") == 0){
        // printf("%s\n","33333" );
        return &std_array_list[0];
    }
}

#endif