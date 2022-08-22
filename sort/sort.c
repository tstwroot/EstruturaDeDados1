#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

long int count = 0;

void mergesort(struct IntVector *vector, int start, int end)
{
    if(end > start)
    {
        count++;
        int middle = start + ((end - start) / 2);
        mergesort(vector, start, middle);
        mergesort(vector, (middle + 1), end);
        merge(vector, start, middle, end);
    }
}

void merge(struct IntVector *vector, int start, int middle, int end)
{
    size_t lSize = (middle - start + 1), rSize = (end - middle);
    int *auxL = (int*)malloc(lSize * sizeof(int));
    int *auxR = (int*)malloc(rSize * sizeof(int));

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
    free(auxL);
    free(auxR);
}