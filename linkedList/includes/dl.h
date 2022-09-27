#ifndef __LD_H__
#define __LD_H__

struct DLNode
{
    int value;
    struct DLNode *next, *back;
};

struct DLinkedList
{
    int size;
    struct DLNode *start, *end;
};

struct DLNode*
newNode(int value);

struct DLinkedList*
newList();

bool 
isEmpty(const struct DLinkedList *dl_list);

void
r_destroy(struct DLNode *dl_node);

void
addFirst(struct DLinkedList *dl_list, int value);

void
r_print(struct DLNode *dl_node);

#endif