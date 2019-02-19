#include <stdio.h>
#include <stdlib.h>
#include "m_queue.h"
//////////////////////////////////////////////queue//
 
#define ERROR -99 //ElementType鐨勭壒娈婂€硷紝鏍囧織閿欒
Queue* am_queue = NULL;
Queue* ay_queue = NULL;
 
Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("空间不足\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}
 
int IsFullQ(Queue* q) {
    return (q->size == MAXSIZE);
}
 
void AddQ(Queue* q, ElementType item) {
    if (IsFullQ(q)) {
        printf("队列已满\n");
        return;
    }
    q->rear++;
    q->rear %= MAXSIZE;
    q->size++;
    q->data[q->rear] = item;
}
 
int IsEmptyQ(Queue* q) {
    return (q->size == 0);
}
 
ElementType DeleteQ(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("空队列\n");
        return ERROR;
    }
    q->front++;
    q->front %= MAXSIZE; //0 1 2 3 4 5
    q->size--;
    return q->data[q->front];
}
 
void PrintQueue(Queue* q) {
    if (IsEmptyQ(q)) {
        printf("空队列\n");
        return;
    }
    printf("打印队列数据元素：\n");
    int index = q->front;
    int i;
    for (i = 0; i < q->size; i++) {
        index++;
        index %= MAXSIZE;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}
//get Queue yuansu
ElementType * GetQueueItems(Queue* q,int * qitems) {
	int index = q->front;
    int i;
    for (i = 0; i < q->size; i++) {
        index++;
        index %= MAXSIZE;
        qitems[i]=q->data[index];
    }    
		return qitems;
}
////////////////////////////////////////queue end
