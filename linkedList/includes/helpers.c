#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helpers.h"
#include "lists.h"

struct MatrixIntVector **createTestMatrix(struct IntVector *vector, int sizeI, long int sizeJ)
{
	struct MatrixIntVector **matrix = (struct MatrixIntVector **)malloc(sizeI * sizeof(struct MatrixIntVector));
	for (int i = 0; i < sizeI; i++)
	{
		matrix[i]->intvector = (struct IntVector *)malloc(sizeof(struct IntVector));
		matrix[i]->intvector->data = (int*)malloc(sizeJ * sizeof(int));
	}

	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			matrix[i]->intvector->data[j] = vector->data[j];
		}
	}
	return (matrix);
}

int get_pivot(int *vetor, unsigned int size)
{
	int maior = 0;
	for (int i = 0; i < size; i++)
	{
		if (vetor[i] > maior)
		{
			maior = vetor[i];
		}
	}

	int Imelhor, melhor;
	for (int dif, i = 0; i < size; i++)
	{
		dif = abs((vetor[i] - (maior / 2)));
		if (i == 0)
			melhor = dif;
		else
		{
			if (dif < melhor)
			{
				melhor = dif;
				Imelhor = i;
			}
		}
	}
	return Imelhor;
}

void swap(long int *__n1, long int *__n2)
{
	long int aux = *__n1;
	*__n1 = *__n2;
	*__n2 = aux;
}

void usage()
{
	puts("USAGE: <size of vector> <max rand>");
}

void writeTimeInAFile(struct timing *time, FILE *output)
{
	output = fopen("output", "w+");
	fprintf(output, "[x] Ordenated vector[%ld] positions with rand range = %d in: %lf seconds\n", time->vector_size, time->rand_max, time->final);
	fclose(output);
}

void printVector(int *vector, unsigned int size)
{
	fprintf(stdout, "Vector[");
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			fprintf(stdout, "%d]\n", vector[i]);
		else
			fprintf(stdout, "%d,", vector[i]);
	}
}

void fillWithRandNums(struct IntVector *vector, long int size, int max)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		vector->data[i] = rand() % max;
	}
}

double getTimeExec(struct timing *time, char *point)
{
	if (strcmp(point, "start") == 0)
	{
		time->start = clock();
	}
	if (strcmp(point, "end") == 0)
	{
		time->end = clock();
		return (time->final = (double)(time->end - time->start) / CLOCKS_PER_SEC);
	}
}