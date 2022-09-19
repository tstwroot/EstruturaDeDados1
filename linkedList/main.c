#include <stdio.h>
#include "./includes/ll.h"
#include "./includes/lists.h"

int main(int argc, char **argv)
{
    struct LinkedList *list = newLinkedList();
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 5);
    addLast(list, 10);
    addOrd(list, 5);
    addOrd(list, 3);
    printLinkedList(list);
}