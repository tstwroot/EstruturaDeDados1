#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct IntVector *create(long int __size)
{
    struct IntVector *vector = (struct IntVector*)calloc(1, sizeof(struct IntVector));
    vector->capacity = __size;
    vector->size = 0;
    vector->data = (long int*)calloc(__size, sizeof(long int));
    return vector;
}

void destroy(struct IntVector *vector)
{
	free(vector);
}

int size(struct IntVector * vector)
{
    return vector->size;
}

int capacity(struct IntVector * vector)
{
    return vector->capacity;
}

int at(struct IntVector * vector, int pos)
{
    if(pos < 0 || pos >= vector->size)
    {
        fprintf(stderr, "Error: Invalid position.\n");
        fprintf(stderr, "Index [%d] is out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    return vector->data[pos];
}

int get(struct IntVector* vector, int pos)
{
    return vector->data[pos];
}

bool isFull(struct IntVector * vector)
{
    if(vector->size == vector->capacity)
    {
        return true;
    }
    return false;
}

/**
 * This function append a value into the vector
 * If this function return 0 nothing has been changed in the vector, or some error occured.
 * If this function return 1, the value was inserted into the vector with success.
 * **/
void append(struct IntVector * vector, int value)
{
    char choice;
    if(isFull(vector))
    {
        fprintf(stdout, "This vector is done. Do you want reallocate one more element ? ");
        scanf(" %c", &choice);
        if(strcmp(&choice, '1') == 0)
        {
            vector = (struct IntVector*)realloc(vector, vector->capacity + 1 * sizeof(struct IntVector));
            vector->capacity++;
            vector->data[vector->capacity+1] = value;
            exit(EXIT_SUCCESS);
        }
        else if(strcmp(&choice, '0') == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            fprintf(stderr, "Invalid Option, nothing happened!\n");
            return 0;
        }
    }
    else
    {
        vector->data[vector->size+1] = value;
        exit(EXIT_SUCCESS);
    }
    
}