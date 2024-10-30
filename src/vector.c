#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int vector_init(Vector *vector, size_t element_size, int initial_capacity){
    vector->data = malloc(initial_capacity * element_size);
    if(vector->data == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    vector->capacity = initial_capacity;
    vector->size = 0;
    vector->element_size = element_size;
    return 0;
}