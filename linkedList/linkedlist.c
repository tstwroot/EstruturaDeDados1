#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct _snode
{
    int value;
    struct _snode *next;
}SNode;

typedef struct _sLinked_list
{
    int size;
    SNode *start;
}LinkedList;

SNode *newNode(int value)
{
    SNode *newNode = (SNode*)calloc(1, sizeof(SNode));
    newNode->value;
    newNode->next = NULL;
    return newNode;
}

LinkedList *newLinkedList()
{
    LinkedList *newList = (LinkedList*)calloc(1, sizeof(LinkedList));
    newList->start = NULL;
    return newList;
}

void addFirst(LinkedList *__linked_list, int value)
{
    SNode *ref = newNode(value);
    ref->next = __linked_list->start;
    __linked_list->start = ref;
    __linked_list->size++;
}

void addLast(LinkedList *__linked_list, int value)
{
    SNode *ref = newNode(value);
    if(__linked_list->start == NULL)
    {
        __linked_list->start = ref;
    }
    else
    {
        SNode *aux = __linked_list->start;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->value = value;
    }
    __linked_list->size++;
}

void printLinkedList(LinkedList *__linked_list)
{
    SNode *ref = __linked_list->start;
    fprintf(stdout, "[");
    while(ref->next != NULL)
    {
        fprintf(stdout, "%d -> ", ref->value);
        ref = ref->next;
    }
    fprintf(stdout, "NULL]\n");
}