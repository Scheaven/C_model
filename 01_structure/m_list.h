#ifndef _M_LIST_H_
#define _M_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#define FElementType float 
#define PLISTMAX 20000 
// List inplementation

typedef struct {
    FElementType data[PLISTMAX];
    int size; 
}List;

extern List *ay_meanlist;
extern List *ay_stdlist;

List* CreateList();
void List_Init(List* list);
void List_Add(List* list, float value);
void List_Show(List* list);
void List_Clear(List* list);

#endif
