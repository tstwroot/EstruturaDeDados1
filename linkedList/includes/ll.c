#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "ll.h"
#include "sort.h"
#include "lists.h"

void *newNode(int value, char type)
{
    if (strcmp(type, "-sl") == 0)
    {
        struct SNode *newNode = (struct SNode *)calloc(1, sizeof(struct SNode));
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }
    else if (strcmp(type, "-dl") == 0)
    {
        struct DSNode *newNode = (struct DSNode *)calloc(1, sizeof(struct DSNode));
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }
    else
    {
        fprintf(stderr, "Error: Invalid Type List!\n");
        return;
    }
}

void *newLinkedList(char type)
{
    if (strcmp(type, "-sl") == 0)
    {

        struct LinkedList *newList = (struct LinkedList *)calloc(1, sizeof(struct LinkedList));
        newList->start = NULL;
        return newList;
    }
    if (strcmp(type, "-dl") == 0)
    {

        struct DLinkedList *newList = (struct DLinkedList *)calloc(1, sizeof(struct DLinkedList));
        newList->start = NULL;
        return newList;
    }
}

void addFirst(struct LinkedList *__linked_list, long int value)
{
    struct SNode *ref = newNode(value);
    ref->next = __linked_list->start;
    __linked_list->start = ref;
    __linked_list->size++;
}

void addLast(struct LinkedList *__linked_list, long int value)
{
    struct SNode *nNode = newNode(value);
    if (__linked_list->start == NULL)
    {
        __linked_list->start = nNode;
    }
    else
    {
        struct SNode *aux = __linked_list->start;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = nNode;
    }
    __linked_list->size++;
}

struct IntVector *vectorize(struct LinkedList *__linked_list)
{
    struct IntVector *intV = (struct IntVector *)malloc(sizeof(struct IntVector));
    intV->data = (long int *)malloc(__linked_list->size * sizeof(long int));
    intV->size = __linked_list->size;
    struct SNode *aux = __linked_list->start;
    for (int i = 0; i < __linked_list->size; i++)
    {
        intV->data[i] = aux->value;
        aux = aux->next;
    }
    return intV;
}

// This function returns 1 if the array is sorted, else it returns 0
int isOrd(struct LinkedList *__linked_list)
{
    if (__linked_list->size > 1)
    {
        struct IntVector *v = vectorize(__linked_list);
        for (int i = 0; i < (v->size - 1); i++)
        {
            if (v->data[i] > v->data[i + 1])
            {
                return 0;
            }
        }
    }
    return 1;
}

int addOrd(struct LinkedList *__linked_list, long int value)
{
    if (isOrd(__linked_list) == 0)
    {
        return 0;
    }

    struct SNode *nNode = newNode(value);

    if (__linked_list->start == NULL)
    {
        __linked_list->start = nNode;
    }
    else
    {
        struct SNode *aux = __linked_list->start;
        while (aux->next->value < value)
        {
            aux = aux->next;
        }

        nNode->next = aux->next;
        aux->next = nNode;
    }
    __linked_list->size++;
}

// segmentation fault function, fix this bug...
void ordAll(struct LinkedList *__linked_list)
{
    struct IntVector *v = vectorize(__linked_list);
    quick(v, 0, v->size);
    struct SNode *aux = __linked_list->start;
    int i = 0;
    while (aux->next != NULL)
    {
        aux->value = v->data[i];
        aux = aux->next;
        i++;
    }
}

void printLinkedList(struct LinkedList *__linked_list)
{
    struct SNode *ref = __linked_list->start;
    fprintf(stdout, "[");
    while (ref != NULL)
    {
        fprintf(stdout, "%ld -> ", ref->value);
        ref = ref->next;
    }
    fprintf(stdout, "NULL]\n");
}

void distruct(struct SNode *node)
{
    if (node->next == NULL)
    {
        return;
    }
    distruct(node->next);
    free(node);
}