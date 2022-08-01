typedef struct FloatVector floatVector;

FloatVector *create(int tam); // check

void destroy(floatVector ** ref_vector);
int size(const floatVector * vector);
int capacity(const floatVector * vector);
float at(const floatVector * vector, int pos);
float get(const floatVector * vector);
void append(floatVector * vector, float n);
void print(const floatVector * vector);

// PODERIA EXISTIR
//bool compare