#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/*
    Struct: Vector

    Contains details of vector

    data     - The stored data within the vector  
    size     - The amount of elements stored within the vector
    capacity - The limit the vector can hold
*/
typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

/*
    Function: vector_init
    
    This function initialises the vector to a specified capacity

    Parameters:
        vector           - Vector instance
        initial_capacity - Specified size for vector capacity
*/
int vector_init(Vector *vector, int initial_capacity);

/*
    Function: vector_grow
    
    This function is a helper function to grow vector when out of bounds

    Parameters:
        vector           - Vector instance
*/
void vector_grow(Vector *vector);

/*
    Function: vector_push_back
    
    Function to push new value onto end of vector

    Parameters:
        vector           - Vector instance
        value            - Value to be added to vector
*/
void vector_push_back(Vector *vector, int value);

/*
    Function: vector_shrink
    
    This function is a helper function to shrink vector when less than a quarter of capacity is being used

    Parameters:
        vector           - Vector instance
*/
void vector_shrink(Vector *vector);

/*
    Function: vector_pop_back
    
    Function to pop value off end of vector

    Parameters:
        vector           - Vector instance
*/
void vector_pop_back(Vector *vector);

/*
    Function: vector_print
    
    Function to print vector entirity

    Parameters:
        vector           - Vector instance
*/
void vector_print(Vector *vector);

#endif
