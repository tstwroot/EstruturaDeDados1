#ifndef _MERGE_H_
#define _MERGE_H_

#include <stdio.h>
#include <stdlib.h>
#include "intvector.h"

void mergesort(struct IntVector *intVector, int start, int end)
{
    if(start < end)
    {
        int middle = (end+start) / 2;
        mergesort(intVector, start, middle);
        mergesort(intVector, middle + 1, end);
        merge2(intVector, start, middle, end);
    }
}

void merge(struct IntVector *intVector, int start, int middle, int end)
{
    int sizeLeft = middle - start, sizeRight = end - middle;
    int auxL[sizeLeft], auxR[sizeRight];
    printf("SIZEL: %d\n", sizeLeft);
    printf("SIZER: %d\n", sizeRight);
    for(int i = 0; i < sizeLeft; i++)
    {
        auxL[i] = intVector->data[start + i];
    }
    for(int i = 0; i < sizeRight; i++)
    {
        auxR[i] = intVector->data[middle + i];
    }
    int i = 0, j = 0, k = start;
    while(i < sizeLeft && j < sizeRight)
    {
        if (auxL[i] <= auxR[j])
        {
            intVector->data[k] = auxL[i];
            i++;
        }

        else
        {
            intVector->data[k] = auxR[j];
            j++;
        }
    }

    while(j < sizeRight)
    {
        intVector->data[k] = auxR[j];
        j++;
        k++;
    }

    while(i < sizeLeft)
    {
        intVector->data[k] = auxL[i];
        k++;
        i++;
    }
}

#endif