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
    puts("Vetor criado!");
    fillWithRandInt(vector, vector->capacity, 10);
    print(vector);
    puts("Iniciando a ordenação!");
    mergesort(vector, 0, vector->capacity);
    puts("Finalizado!");
    print(vector);
    destroy(vector);
}