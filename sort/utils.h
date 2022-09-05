#ifndef __UTILS_H__
#define __UTILS_H__
#include <time.h>

struct timing 
{
	clock_t start, end;
	double final;
	unsigned int vector_size;
	int rand_max;
};


struct MatrixIntVector **createTestMatrix(struct IntVector *vector, int sizeI, long int sizeJ);
void usage();
void fillWithRandNums(struct IntVector *vector, long int size, int max);
void printVector(int *, unsigned int);
double getTimeExec(struct timing *, char *);
void writeTimeInAFile(struct timing*, FILE*);
int get_pivot(int *vetor, unsigned int size);
void swap(long int*, long int*);

#endif