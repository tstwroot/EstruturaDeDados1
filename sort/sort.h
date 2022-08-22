#ifndef _SORT_H_
#define _SORT_H_

#include "lists.h"

void mergesort(struct IntVector *intVector, int start, int end);
void merge(struct IntVector *intVector, int start, int middle, int end);

#endif