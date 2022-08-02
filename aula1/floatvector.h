#include <stdbool.h>

typedef struct FloatVector floatVector;

FloatVector *create(int tam);                   // check

void destroy(FloatVector ** ref_vector);        // check
int size(const FloatVector * vector);           // check
int capacity(const FloatVector * vector);       // check
float at(const FloatVector * vector, int pos);  
float get(const FloatVector * vector, int pos);
bool isFull(const FloatVector * vector);       
void append(FloatVector * vector, float n);     
void print(const FloatVector * vector);         

// PODERIA EXISTIR
//bool compare