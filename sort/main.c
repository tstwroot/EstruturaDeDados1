#include <stdio.h>
#include <stdlib.h>
#include "intvector.h"
#include "merge.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Invalid arguments! Size of vector needed!\n");
        exit(EXIT_FAILURE);
    }
    struct IntVector *vector;
    vector = create(atoi(argv[1]));
    fillWithRandInt(vector, vector->capacity, 10);
    mergesort(vector, 0, vector->capacity);
    print(vector);
    destroy(vector);
}