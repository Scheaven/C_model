#ifndef _M_QUEUE_H_
#define _M_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#define ElementType int //瀛樺偍鏁版嵁鍏冪礌鐨勭被鍨?
#define MAXSIZE 200 //瀛樺偍鏁版嵁鍏冪礌鐨勬渶澶т釜鏁?

typedef struct {
    ElementType data[MAXSIZE];
    int front; //璁板綍闃熷垪澶村厓绱犱綅缃?
    int rear; //璁板綍闃熷垪灏惧厓绱犱綅缃?
    int size; //瀛樺偍鏁版嵁鍏冪礌鐨勪釜鏁?
}Queue;

extern Queue* am_queue;
extern Queue* ay_queue;

Queue* CreateQueue();

int IsFullQ(Queue* q);
void AddQ(Queue* q, ElementType item);
int IsEmptyQ(Queue* q);
ElementType DeleteQ(Queue* q);
void PrintQueue(Queue* q);
ElementType * GetQueueItems(Queue* q,int * qitems);

#endif
