#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    void *data;
    int size;
    int capacity;
    size_t element_size;
} Vector;

int initialise_vector(Vector *vector, size_t element_size, int initial_capacity);

#endif
