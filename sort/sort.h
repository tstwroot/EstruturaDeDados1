#ifndef _SORT_H_
#define _SORT_H_

#include "lists.h"
void swap(int*, int*);
void bubble(struct IntVector*, int);
void selectionSort(struct IntVector*, int);
void mergesort(struct IntVector *, int , int );
void merge(struct IntVector*, int , int , int );
void quicksort_mp(struct IntVector*, int, int );
void (*sort_functions[])(int *, int, int);

#endif