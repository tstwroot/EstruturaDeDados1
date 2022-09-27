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

struct DSNode
{
    long int value;
    struct SNode *next, *back;
};

struct DLinkedList
{
    long int size;
    struct DSNode *start;

};

void SNode *newNode(int);
void LinkedList *newLinkedList(char type);
void addFirst(struct LinkedList *__linked_list, long int value);
void addLast(struct LinkedList *__linked_list, long int value);
int addOrd(struct LinkedList *__linked_list, long int value);
void printLinkedList(struct LinkedList *__linked_list);
struct IntVector *vectorize(struct LinkedList *__linked_list);
int isOrd(struct LinkedList *__linked_list);
void ordAll(struct LinkedList *__linked_list);
void distruct(struct SNode *node);

// Para fazer

void dll_destroy(struct DLinkedList *);

#endif    struct SNode     struct SNode 