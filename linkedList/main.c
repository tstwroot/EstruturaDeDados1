#include <stdio.h>
#include "./includes/ll.h"
#include "./includes/lists.h"

int main(int argc, char **argv)
{
    struct LinkedList *list = newLinkedList();
    addLast(list, 1);
    addLast(list, 9);
    addLast(list, 3);
    addLast(list, 8);
    printLinkedList(list);
    ordAll(list);
    printLinkedList(list);
}