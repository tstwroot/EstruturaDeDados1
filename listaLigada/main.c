#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node *next;
};

struct List
{
	int size, capacity;
	struct Node *nodeList;
};

struct List *createList()
{
	struct List *newList = (struct List*)malloc(sizeof(struct List));
	newList->nodeList = (struct Node*)malloc(sizeof(struct Node));
	newList->capacity = 1;
	newList->size = 0;
	return newList;
}

void destroyList(struct List * list)
{
	free(list);
}

void insertNode(struct List * list, int value)
{
	struct Node *ref = list->nodeList;
	int count = 0;
	do
	{
		if(list->size == count)
		{
			ref->value = value;
			list->size++;
			break;
		}
		else
		{
			ref = ref->next;
			count++;
		}	
	}while(ref->next != NULL);
}

void printNode(struct List * list)
{
	struct Node *ref = list->nodeList;
	do
	{
		printf("%d\n", ref->value); 
	}
	while(ref->next != NULL);
}

int main(void)
{
	struct List *mylist = createList();
	insertNode(mylist, 666);
	// insertNode(mylist, 444);
	printNode(mylist);
	destroyList(mylist);
}