#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int vector_init(Vector *vector, int initial_capacity){
    vector->data = (int*) malloc(initial_capacity * sizeof(int));
    if(vector->data == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    vector->capacity = initial_capacity;
    vector->size = 0;
    return 0;
}

void vector_grow(Vector *vector){
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity * sizeof(int));
}

void vector_push_back(Vector *vector, int value){
    if (vector->size == vector->capacity) {
        vector_grow(vector);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

void vector_print(Vector *vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}