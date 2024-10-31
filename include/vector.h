#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/*
    Struct: Vector

    Contains details of the vector.

    Members:
        data     - Pointer to the stored data within the vector.  
        size     - Number of elements currently stored in the vector.
        capacity - Maximum number of elements the vector can hold.
*/
typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

/*
    Function: vector_init
    
    Initializes the vector with a specified initial capacity.

    Parameters:
        vector           - Pointer to the Vector instance to initialize.
        initial_capacity - Initial capacity for the vector.
    
    Returns:
        0 if successful; -1 if memory allocation fails.
*/
int vector_init(Vector *vector, int initial_capacity);

/*
    Function: vector_grow
    
    Expands the vector's capacity when it reaches its limit.

    Parameters:
        vector - Pointer to the Vector instance that needs to grow.
*/
void vector_grow(Vector *vector);

/*
    Function: vector_push_back
    
    Adds a new value to the end of the vector.

    Parameters:
        vector - Pointer to the Vector instance.
        value  - The value to be added to the vector.
*/
void vector_push_back(Vector *vector, int value);

/*
    Function: vector_shrink
    
    Reduces the vector's capacity when less than a quarter of its capacity is used.

    Parameters:
        vector - Pointer to the Vector instance to shrink.
*/
void vector_shrink(Vector *vector);

/*
    Function: vector_pop_back
    
    Removes the last value from the vector.

    Parameters:
        vector - Pointer to the Vector instance.
*/
void vector_pop_back(Vector *vector);

/*
    Function: vector_get_value_at_index
    
    Retrieves the data at a specific index in the vector.

    Parameters:
        vector - Pointer to the Vector instance.
        index  - The index of the element to retrieve.
    
    Returns:
        The value at the specified index, or -1 if the index is out of bounds.
*/
int vector_get_value_at_index(Vector *vector, int index);

/*
    Function: vector_find_index_of_value
    
    Searches for the first occurrence of a specified value within the vector
    and returns its index.

    Parameters:
        vector - Pointer to the Vector instance.
        value  - The value to search for within the vector.
    
    Returns:
        The index of the first occurrence of the specified value if found;
        -1 if the value is not present in the vector.
*/
int vector_find_index_of_value(Vector *vector, int value);

/*
    Function: vector_print
    
    Prints all elements in the vector.

    Parameters:
        vector - Pointer to the Vector instance.
*/
void vector_print(Vector *vector);