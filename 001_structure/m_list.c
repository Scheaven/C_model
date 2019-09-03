#include <stdio.h>
#include <stdlib.h>
#include "m_list.h"
List* ay_meanlist = NULL;
List* ay_stdlist  = NULL;
 
List* CreateList(){
    List* list = (List*)malloc(sizeof(List));
    if (!list) {
        printf("space is not enough!\n");
        return NULL;
    }
    List_Init(list);
    return list;
} 

void List_Init(List* list){
    list->size = 0;
}
 
void List_Add(List* list, float value){
    if(list->size>=PLISTMAX){
        printf("The list is full!");
    }else{
        list->data[list->size++] = value;
    }
}
 
void List_Show(List* list){
    printf("len=%d values=", list->size);
    for (int i = 0; i < list->size; ++i)
    {
        printf("%f", list->data[i]);
    }
    printf("\n");
}

void List_Clear(List* list){
    list->size=0;
}
