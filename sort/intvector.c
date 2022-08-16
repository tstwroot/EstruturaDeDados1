#include "intvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IntVector *create(int tam)
{
    struct IntVector *vet = (struct IntVector*)calloc(1, sizeof(struct IntVector));
    vet->capacity = tam;
    vet->size = 0;
    vet->data = (float*)calloc(tam, sizeof(float));
    return vet;
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
    return vector->size;
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

int get(struct IntVector * vector, int pos)
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
        if(strcmp(choice, "1"))
        {
            vector = (struct IntVector*)realloc(vector, vector->capacity + 1 * sizeof(struct IntVector));
            vector->capacity++;
            vector->data[vector->capacity+1] = value;
            return 1;
        }
        else if(strcmp(choice, "0"))
        {
            return 0;
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
        return 1;
    }
    
}

void print(struct IntVector *vector)
{
    printf("vector[");
    for(int i = 0; i < vector->size; i++)
    {
        if(i == vector->size - 1)
        {
            printf("%d,");
        }
        else printf("%d]");
    }
}