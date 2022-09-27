#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dl.h"

struct DLNode*
newNode(int value)
{
    struct DLNode *new_dlnode = (struct DLNode*)malloc(sizeof(struct DLNode));
    new_dlnode->next = NULL;
    new_dlnode->back = NULL;
    new_dlnode->value = value;
    return(new_dlnode);
}

struct DLinkedList*
newList()
{
    struct DLinkedList *new_dlist = (struct DLNode*)malloc(sizeof(struct DLinkedList));
    new_dlist->start = NULL;
    new_dlist->end = NULL;
    new_dlist->size = 0;
    return(new_dlist);
}

bool 
isEmpty(const struct DLinkedList *dl_list)
{
    return(dl_list->size == 0);
}

void
r_destroy(struct DLNode *dl_node)
{
    if(dl_node->next == NULL)
    {
        return;
    }
    r_destroy(dl_node->next);
    free(dl_node);
    dl_node = NULL;
}

void
addFirst(struct DLinkedList *dl_list, int value)
{
    struct DLNode *new_dlnode = newNode(value);

    if(isEmpty(dl_list))
    {
        dl_list->start = new_dlnode;
        dl_list->end = new_dlnode;
    }
    else
    {
        new_dlnode->next = dl_list->start;
        dl_list->start->back = new_dlnode;
    }
    dl_list->start = new_dlnode;
    dl_list->size++;
}

void
r_print(struct DLNode *dl_node)
{
    if(dl_node == NULL)
    {
        return;
    }
    printf("%d ", dl_node->value);
    r_print(dl_node->next);
}