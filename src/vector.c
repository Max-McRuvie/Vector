#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

// Initializes the vector with a given initial capacity.
int vector_init(Vector *vector, int initial_capacity) {
    vector->data = (int*) malloc(initial_capacity * sizeof(int));
    if (vector->data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    vector->capacity = initial_capacity;
    vector->size = 0;
    return 0;
}

// Grows the vector capacity when it is full.
void vector_grow(Vector *vector) {
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity * sizeof(int));
}

// Pushes a new value to the end of the vector.
void vector_push_back(Vector *vector, int value) {
    if (vector->size == vector->capacity) {
        vector_grow(vector);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

// Shrinks the vector when less than a quarter of its capacity is used.
void vector_shrink(Vector *vector) {
    if (vector->size < vector->capacity / 4 && vector->capacity > 1) {
        vector->capacity /= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(int));
        if (vector->data == NULL) {
            printf("Memory allocation failed!\n");
        }
    }
}

// Pops a value from the end of the vector.
void vector_pop_back(Vector *vector) {
    if (vector->size > 0) {
        vector->size--;
        vector_shrink(vector);
    }
}

// Retrieves data at a specific index.
int vector_get_value_at_index(Vector *vector, int index) {
    if (index >= 0 && index < vector->size) {
        return vector->data[index];
    } else {
        printf("Invalid index!\n");
        return -1;
    }
}

// Finds the index of a specified value.
int vector_find_index_of_value(Vector *vector, int value) {
    for (int i = 0; i < vector->size; i++) {
        if (vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

// Prints the entire vector.
void vector_print(Vector *vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}

// Clears all elements in the vector.
void vector_clear(Vector *vector) {
    for (int i = 0; i < vector->size; i++) {
        vector->data[i] = 0; 
    }
    vector->size = 0;
    vector_shrink(vector);
}

// Frees the vector from memory and resets its properties.
void vector_destroy(Vector *vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}