#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct SNode
{
    long int value;
    struct SNode *next;
};

struct LinkedList
{
    long int size;
    struct SNode *start;
};

struct SNode *newNode(int);
struct LinkedList *newLinkedList();
void addFirst(struct LinkedList *__linked_list, long int value);
void addLast(struct LinkedList *__linked_list, long int value);
int addOrd(struct LinkedList *__linked_list, long int value);
void printLinkedList(struct LinkedList *__linked_list);
struct IntVector *vectorize(struct LinkedList *__linked_list);
int isOrd(struct LinkedList *__linked_list);

#endif