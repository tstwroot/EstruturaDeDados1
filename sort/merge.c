#ifndef _MERGE_H_
#define _MERGE_H_

#include <stdio.h>
#include <stdlib.h>
#include "intvector.h"

void mergesort(struct IntVector *intVector, int start, int end)
{
    if (start < end)
    {
        int meio = start + (end - start) / 2;
        mergesort(intVector, start, meio);
        mergesort(intVector, meio + 1, end);
        merge(intVector, start, meio, end);
    }
}

void merge(struct IntVector *intVector, int start, int middle, int end)
{
    int sizeLeft = middle - start + 1, sizeRight = end - middle;
    int auxL[sizeLeft], auxR[sizeRight];
    for (int i = 0; i < sizeLeft; i++)
    {
        auxL[i] = intVector->data[start + i];
    }
    for (int i = 0; i < sizeRight; i++)
    {
        auxR[i] = intVector->data[middle + i];
    }
    int i = 0, j = 0, k = 0;
    while (i < sizeLeft && j < sizeRight)
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