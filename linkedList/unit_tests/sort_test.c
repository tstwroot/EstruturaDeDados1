#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../includes/lists.h"
#include "../includes/sort.h"
#include "../includes/utils.h"
#define FUNCTIONS 4

// need to transform all this thing in a unit test

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Error: This software requires 2 arguments to work!\n");
        usage();
        exit(EXIT_FAILURE);
    }

    void (*sort_functions[])(struct IntVector *, int, int) = {
        bubble,
        selectionSort,
        mergesort,
        quicksort_mp
    };

    long int size_vector = atoi(argv[1]), rand_max = atoi(argv[2]);
    struct IntVector *vector = create(size_vector);
    fillWithRandNums(vector, size_vector, rand_max);

    struct IntVector **matrix;
    matrix = createTestMatrix(vector, FUNCTIONS, size_vector);
    struct timing *time = (struct timing *)malloc(sizeof(struct timing));
    FILE *output;

    for (int i = 0; i < FUNCTIONS; i++)
    {
        getTimeExec(time, "start");
        (*sort_functions[i])(matrix[i], 0, size_vector);
        getTimeExec(time, "end");
        writeTimeInAFile(time, output);
        memset(time, 0, sizeof(time));
    }
}
