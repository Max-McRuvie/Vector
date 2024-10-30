#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

int vector_init(Vector *vector, int initial_capacity);
void vector_grow(Vector *vector);
void vector_push_back(Vector *vector, int value);
void vector_print(Vector *vector);

#endif
