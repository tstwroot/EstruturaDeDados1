#ifndef _MERGE_H_
#define _MERGE_H_

#include <stdio.h>
#include <stdlib.h>
#include "intvector.h"

void printVector(int *auxLeft, int leftSize, int *auxRight, int rightSize)
{
    for(int i = 0; i < leftSize; i++)
    {
        printf("%d ", auxLeft[i]);
    }

    printf("\n");
    for(int i = 0; i < rightSize; i++)
    {
        printf("%d ", auxRight[i]);
    }

    printf("\n");
}

void mergesort(struct IntVector *vector, int start, int end)
{
    if(end > start)
    {
        int middle = start + ((end - start) / 2);
        mergesort(vector, start, middle);
        mergesort(vector, (middle + 1), end);
        merge(vector, start, middle, end);
    }
}

void merge(struct IntVector *vector, int start, int middle, int end)
{
    size_t lSize = (middle - start + 1), rSize = (end - middle);
    int auxL[lSize], auxR[rSize];

    for(int i = 0; i < lSize; i++)
        auxL[i] = vector->data[start + i];
    for(int i = 0; i < rSize; i++)
        auxR[i] = vector->data[middle + 1 + i];

    int i = 0, j = 0, k = start;
    while(i < lSize && j < rSize)
    {
        if(auxL[i] <= auxR[j])
        {
            vector->data[k] = auxL[i];
            i++;
        }
        else
        {
            vector->data[k] = auxR[j];
            j++;
        }
        k++;
    }

    while(i < lSize)
    {
        vector->data[k] = auxL[i];
        i++;
        k++;
    }

    while(j < rSize)
    {
        vector->data[k] = auxR[j];
        j++;
        k++;
    }
}
#endif