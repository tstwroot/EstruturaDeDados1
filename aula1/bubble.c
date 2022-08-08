#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int *genRandVector(int size, int max)
{
    srand(time(NULL));
    int *vector = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        vector[i] = rand() % max;
    }

    return vector;
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int vector[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        bool test = false;
        for(int j = 0; j < (size - i); j++)
        {
            if(vector[j] > vector[j + 1])
            {
                test = true;
                swap(&vector[j], &vector[j + 1]);
            }
        }
        if(test == false) break;
    }
}

void printVector(int vector[], int size)
{
    printf("Vector[");
    for(int i = 0; i < size; i++)
    {
        if(i == size-1) printf("%d]", vector[i]);
        else printf("%d,", vector[i]);
    }
    printf("\n");
}

#define SIZE 100000

int main(void)
{
    double time_spent = 0.0;
    clock_t begin = clock();

    int *vector = genRandVector(SIZE, SIZE);
    bubble(vector, SIZE);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printVector(vector, SIZE);
    printf("Tempo de execução: %f segundos\n", time_spent);
}