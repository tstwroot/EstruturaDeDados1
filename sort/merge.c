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
        merge(intVector, start, middle, end);
    }
}

void merge(struct IntVector *intVector, int start, int middle, int end)
{
    int auxLeft[(middle)];
    int auxRight[(end - (middle + 1))];
    for(int i = start; i <= middle; i++)
    {
        auxLeft[i] = intVector->data[i];
    }
    for(int i = (middle+1); i <= end; i++)
    {
        auxRight[i] = intVector->data[i];
    }
    int i = 0, j = 0, k = start;
    while(k <= end)
    {
        if(i >= middle+1)
        {
            intVector->data[k] = auxRight[j];
            j++;
        }
        else if(j >= (end - (middle)))
        {
            intVector->data[k] = auxLeft[i];
            i++;
        }
        else
        {
            if(auxLeft[i] < auxRight[j])
            {
                intVector->data[k] = auxLeft[i];
                i++;
            }
            else
            {
                intVector->data[k] = auxRight[j];
                j++;
            }
        }
        k++;
    }
}

#endif