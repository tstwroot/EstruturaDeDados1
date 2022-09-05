#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct SNode
{
    int value;
    struct SNode *next;
};

struct LinkedList
{
    int size;
    struct SNode *start;
};

struct SNode *newNode(int value)
{
    struct SNode *newNode = (struct SNode*)calloc(1, sizeof(struct SNode));
    newNode->value;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList *newLinkedList()
{
    struct LinkedList *newList = (struct LinkedList*)calloc(1, sizeof(struct LinkedList));
    newList->start = NULL;
    return newList;
}

void addFirst(struct LinkedList *__linked_list, int value)
{
    struct SNode *ref = newNode(value);
    ref->next = __linked_list->start;
    __linked_list->start = ref;
    __linked_list->size++;
}

void addLast(struct LinkedList *__linked_list, int value)
{
    struct SNode *ref = newNode(value);
    if(__linked_list->start == NULL)
    {
        __linked_list->start = ref;
    }
    else
    {
        struct SNode *aux = __linked_list->start;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->value = value;
    }
    __linked_list->size++;
}

void printstruct(struct LinkedList *__linked_list)
{
    struct SNode *ref = __linked_list->start;
    fprintf(stdout, "[");
    while(ref->next != NULL)
    {
        fprintf(stdout, "%d -> ", ref->value);
        ref = ref->next;
    }
    fprintf(stdout, "NULL]\n");
}