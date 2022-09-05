#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lists.h"
#include "sort.h"
#include "utils.h"
#define FUNCTIONS 4

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Error: This software requires 2 arguments to work!\n");
        usage();
        exit(EXIT_FAILURE);
    }

    int size_vector = atoi(argv[1]), rand_max = atoi(argv[2]);
    int *vector = create(size_vector);
    fillWithRandNums(vector, size_vector, rand_max);

    int **matrix;
    matrix = createMatrix(vector, FUNCTIONS, size_vector);
    struct timing *time = (struct timing*)malloc(sizeof(struct timing));
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
