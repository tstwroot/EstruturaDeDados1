#include "floatvector.hpp"
#include <iostream>

using namespace std;

struct FloatVector {
    int capacity; // num max de elementos
    int size; // quantidade atual de elementos
    float *data;
};

FloatVector *create(int tam)
{
    FloatVector *vet = (FloatVector*)calloc(1, sizeof(FloatVector));
    vet->capacity = tam;
    vet->size = 0;
    vet->data = (float*)calloc(tam, sizeof(float));
    return vet;
}

void destroy(FloatVector **vet_ref)
{
    FloatVector *vet = *vet_ref;
    free(vet->data);
    free(vet);
    *vet_ref = NULL;
}


int main(int argc, char *argv[]) 
{
  
}