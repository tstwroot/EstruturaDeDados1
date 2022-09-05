#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct _snode SNode;
typedef struct _sLinked_list LinkedList;

SNode *newNode(int);
LinkedList *newLinkedList();
void addFirst(LinkedList *__linked_list, int value);
void addLast(LinkedList *__linked_list, int value);

#endif