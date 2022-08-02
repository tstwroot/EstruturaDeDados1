#include "floatvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FloatVector {
    int capacity; // num max de elementos
    int size; // quantidade atual de elementos
    float *data;
}FloatVector;

FloatVector *create(int tam)
{
    FloatVector *vet = (FloatVector*)calloc(1, sizeof(FloatVector));
    vet->capacity = tam;
    vet->size = 0;
    vet->data = (float*)calloc(tam, sizeof(float));
    return vet;
}

void destroy(FloatVector **vet_ref)
{
    FloatVector *vet = *vet_ref;
    free(vet);
    *vet_ref = NULL;
}

int size(const FloatVector * vector)
{
    return vector->size;
}

int capacity(const FloatVector * vector)
{
    return vector->size;
}

float at(const FloatVector * vector, int pos)
{
    if(pos < 0 || pos >= vector->size)
    {
        fprintf(stderr, "Error: Invalid position.\n");
        fprintf(stderr, "Index [%d] is out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    return vector->data[pos];
}

float get(const FloatVector * vector, int pos)
{
    return vector->data[pos];
}

bool isFull(const FloatVector * vector)
{
    if(vector->size == vector->capacity)
    {
        return true;
    }
    return false;
}

/***
 * This function append a value into the vector
 * If this function return 0 nothing has been changed in the vector, or some error occured.
 * If this function return 1, the value was inserted into the vector with success.
 * ***/
void append(FloatVector * vector, float value)
{
    char choice;
    if(isFull(vector))
    {
        fprintf(stdout, "This vector is done. Do you want reallocate one more element ? ");
        scanf(" %c", &choice);
        if(strcmp(choice, "1"))
        {
            vector = (FloatVector*)realloc(vector, vector->capacity + 1 * sizeof(FloatVector));
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

int main(int argc, char *argv[]) 
{
  
}