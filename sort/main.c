#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intvector.h"
#include "merge.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Invalid arguments! Size of vector needed!\n");
        exit(EXIT_FAILURE);
    }
    clock_t start = clock();
    
    struct IntVector *vector;
    size_t size_of_vector = atoi(argv[1]);
    vector = create(size_of_vector+1);
    fillWithRandInt(vector, vector->capacity, size_of_vector);
    mergesort(vector, 0, vector->capacity - 1);
    destroy(vector);
    clock_t end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total: %lf\n", total);
}