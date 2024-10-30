#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Function to initialise vector
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

// Helper function to grow vector when out of bounds
void vector_grow(Vector *vector){
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity * sizeof(int));
}

// Function to push new value onto end of vector
void vector_push_back(Vector *vector, int value){
    if (vector->size == vector->capacity) {
        vector_grow(vector);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

// Helper function to shrink vector when less of a quarter of capacity is being used
void vector_shrink(Vector *vector){
    if(vector->size < vector->capacity / 4 && vector->capacity > 1){
        vector->capacity /= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(int));
        if(vector->data == NULL){
            printf("Memory allocation failed!\n");
        }
    }
}

// Function to pop value off end of vector
void vector_pop_back(Vector *vector){
    if(vector->size > 0) {
        vector->size--;
        vector_shrink(vector);
    }
}

// Function to retrieve data at a specfic index
int vector_get_value_at_index(Vector *vector, int index){
    if(index >= 0 && index < vector->size){
        return vector->data[index];
    } else {
        printf("Invalid index!\n");
        return -1;
    }
}

// Function to print vector entirity
void vector_print(Vector *vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}