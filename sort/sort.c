#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void bubble(struct IntVector *vector, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool test = false;
        for (int j = 0; j < (size - i); j++)
        {
            if (vector->data[j] > vector->data[j + 1])
            {
                test = true;
                swap(&vector->data[j], &vector->data[j + 1]);
            }
        }
        if (test == false)
            break;
    }
}

void selectionSort(struct IntVector *vector, int start, int end)
{
    int minor = start;
    for (int i = 0; i < end; i++)
    {
        for (int j = i; j < end; j++)
        {
            if (vector->data[j] < vector->data[minor])
            {
                minor = j;
            }
        }
        if (minor != i)
        {
            swap(&vector->data[i], &vector->data[minor]);
        }
    }
}

void mergesort(struct IntVector *vector, int start, int end)
{
    if (end > start)
    {
        int middle = start + ((end - start) / 2);
        mergesort(vector, start, middle);
        mergesort(vector, (middle + 1), end);
        // merge(vector, start, middle, end);
        
        size_t lSize = (middle - start + 1), rSize = (end - middle);
        int *auxL = (int *)malloc(lSize * sizeof(int));
        int *auxR = (int *)malloc(rSize * sizeof(int));

        for (int i = 0; i < lSize; i++)
            auxL[i] = vector->data[start + i];
        for (int i = 0; i < rSize; i++)
            auxR[i] = vector->data[middle + 1 + i];

        int i = 0, j = 0, k = start;
        while (i < lSize && j < rSize)
        {
            if (auxL[i] <= auxR[j])
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

        while (i < lSize)
        {
            vector->data[k] = auxL[i];
            i++;
            k++;
        }

        while (j < rSize)
        {
            vector->data[k] = auxR[j];
            j++;
            k++;
        }
        free(auxL);
        free(auxR);
    }
}

void merge(struct IntVector *vector, int start, int middle, int end)
{
    size_t lSize = (middle - start + 1), rSize = (end - middle);
    int *auxL = (int *)malloc(lSize * sizeof(int));
    int *auxR = (int *)malloc(rSize * sizeof(int));

    for (int i = 0; i < lSize; i++)
        auxL[i] = vector->data[start + i];
    for (int i = 0; i < rSize; i++)
        auxR[i] = vector->data[middle + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < lSize && j < rSize)
    {
        if (auxL[i] <= auxR[j])
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

    while (i < lSize)
    {
        vector->data[k] = auxL[i];
        i++;
        k++;
    }

    while (j < rSize)
    {
        vector->data[k] = auxR[j];
        j++;
        k++;
    }
    free(auxL);
    free(auxR);
}

void quicksort_mp(struct IntVector *vector, int start, int end)
{
    int i = start, j = end - 1;
    int pivo = vector->data[get_pivot(vector->data, (start + end))];
    while (i <= j)
    {
        while (vector->data[i] < pivo && i < end)
        {
            i++;
        }
        while (vector->data[j] > pivo && j > start)
        {
            j--;
        }
        if (i <= j)
        {
            swap(vector->data + i, vector->data + j);
            i++;
            j--;
        }
    }
    if (j > start)
        quick(vector->data, start, j + 1);
    if (i < end)
        quick(vector->data, i, end);
}

void quick(int *vector, int start, int end)
{
    int i = start, j = end - 1;
    int pivo = vector[(start + end) / 2];
    while (i <= j)
    {
        while (vector[i] < pivo && i < end)
        {
            i++;
        }
        while (vector[j] > pivo && j > start)
        {
            j--;
        }
        if (i <= j)
        {
            swap(vector + i, vector + j);
            i++;
            j--;
        }
    }
    if (j > start)
        quick(vector, start, j + 1);
    if (i < end)
        quick(vector, i, end);
}