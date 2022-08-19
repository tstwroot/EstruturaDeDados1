#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_
#include <stdbool.h>

struct IntVector {
    int capacity, size;
    long int *data;
};

struct IntVector *create(long int tam);           
void destroy(struct IntVector *vector);
int size(struct IntVector *vector);
int capacity(struct IntVector *vector);
int at(struct IntVector *vector, int pos);
int get(struct IntVector *vector, int pos);
bool isFull(struct IntVector *vector);
void append(struct IntVector *vector, int n);
void fillWithRandInt(struct IntVector *vector, int size, int max_rand);
void print(struct IntVector *vector);

#endif