#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_
#include <stdbool.h>

struct IntVector {
    int capacity, size;
    int *data;
};

struct IntVector *create(int tam);           
void destroy(struct IntVector *vector);
int size(struct IntVector *vector);
int capacity(struct IntVector *vector);
int at(struct IntVector *vector, int pos);
int get(struct IntVector *vector, int pos);
bool isFull(struct IntVector *vector);
void append(struct IntVector *vector, int n);
void print(struct IntVector *vector);

#endif