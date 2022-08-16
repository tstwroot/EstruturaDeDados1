#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *__str;
	struct Node *__next;
}Node;

typedef struct
{
	Node *hash_table;
}HashTable;

int hashIt(char *__str)
{
	if(__str == NULL)
	{
		fprintf(stderr, "Invalid char pointer\n");
		exit(EXIT_FAILURE);
	}
	int hash = 0;
	for(int i = 0; __str[i] != '\0'; i++)
	{
		hash = hash + __str[i];
	}
	return (hash % 100);
}

void createHashTable(HashTable *__hashtable, int __size)
{
	__hashtable = (HashTable *)malloc(__size * sizeof(HashTable));
}

Node *createNode(char *__str, Node *__next)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->__str = (char*)malloc(strlen(__str) * sizeof(char));
	strcpy(newNode->__str, __str);
	newNode->__next = __next;
	return newNode;
}

int insertValue(Node *__hashtable, char *__str)
{
	if(__hashtable == NULL || __str == NULL)
	{
		fprintf(stderr, "Invalid pointer\n");
		exit(EXIT_FAILURE);
	}
	int index = hashIt(__str);
	if(strcmp(__hashtable[index].__str, __str) != 0 && __hashtable[index].__next != NULL)
	{	
		Node *__nodeRef = &__hashtable[index].__next;
		while(__nodeRef)
		{
			if(__nodeRef->__str == __str)
			{
				fprintf(stdin, "This value is already included!\n");
				return 0;
			}
			__nodeRef = __nodeRef->__next;
		}
		__nodeRef->__next = createNode(__str, NULL);
		if(__nodeRef->__next != NULL) return 1;
		else
		{
			fprintf(stderr, "Impossible allocate a new node!\n");
			return 1;
		}
	}
}

int main(int argc, char* argv[])
{
	HashTable *hash_table;
	createHashTable(hash_table, 100);
	char *nome = "Pablitos";
	insertValue(hash_table, nome);
}