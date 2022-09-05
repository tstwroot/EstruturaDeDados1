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

void swap(int *, int *);
void usage();
void destroy(int *);
void fillWithRandNums(int *, unsigned int, int);
void printVector(int *, unsigned int);
double getTimeExec(struct timing *, char *);
void writeTimeInAFile(struct timing*, FILE*);
int **createMatrix(int *, int, int);
int get_pivot(int *vetor, unsigned int size);
void swap(int *, int *);

#endif