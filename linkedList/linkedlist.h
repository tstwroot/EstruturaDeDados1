#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct SNode;
struct LinkedList;

struct SNode *newNode(int);
struct LinkedList *newLinkedList();
void addFirst(struct LinkedList *__linked_list, int value);
void addLast(struct LinkedList *__linked_list, int value);
void printLinkedList(struct LinkedList *__linked_list);

#endif