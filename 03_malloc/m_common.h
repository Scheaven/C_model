#ifndef _M_COMMON_H_
#define _M_COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <kernel.h>
//#define AXISQUEUE_SIZE 50    //队列中元素个数最大限制
//#define AMQUEUE_SIZE 50    //队列中元素个数最大限制
//#define QUEUE_TYPE int    //    定义队列类型为int



int16_t *m_malloc(int size);
int16_t *new_queue(int size,char *name);
int16_t *new_list(int size,char *name);
#endif