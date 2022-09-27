#include <stdio.h>
#include <stdbool.h>
#include "./includes/dl.h"

int main(int argc, char **argv)
{
    struct DLinkedList *list = newList();
    addFirst(list, 4);
    addFirst(list, 7);
    addFirst(list, 1);
    addFirst(list, 40);
    r_print(list);
    r_destroy(list);
}