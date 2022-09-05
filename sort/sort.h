#ifndef _SORT_H_
#define _SORT_H_
#include "lists.h"

void bubble(struct IntVector*, int);
void selectionSort(struct IntVector*, int, int);
void mergesort(struct IntVector *, int , int );
void merge(struct IntVector*, int , int , int);
void quicksort_mp(struct IntVector*, int, int );
void quick(int*, int, int );

#endif