#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/*
    Struct: Vector

    Contains details of the vector.

    data     - The stored data within the vector.  
    size     - The number of elements stored within the vector.
    capacity - The maximum number of elements the vector can hold.
*/
typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

/*
    Function: vector_init
    
    Initializes the vector to a specified capacity.

    Parameters:
        vector           - Pointer to the Vector instance to initialize.
        initial_capacity - The initial capacity for the vector.
    
    Returns:
        0 if successful, or -1 if there was an error.
*/
int vector_init(Vector *vector, int initial_capacity);

/*
    Function: vector_grow
    
    Grows the vector when it is out of bounds.

    Parameters:
        vector - Pointer to the Vector instance.
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
    
    Shrinks the vector when less than a quarter of its capacity is being used.

    Parameters:
        vector - Pointer to the Vector instance.
*/
void vector_shrink(Vector *vector);

/*
    Function: vector_pop_back
    
    Removes the value at the end of the vector.

    Parameters:
        vector - Pointer to the Vector instance.
*/
void vector_pop_back(Vector *vector);

/*
    Function: vector_get_value_at_index
    
    Retrieves data at a specific index in the vector.

    Parameters:
        vector - Pointer to the Vector instance.
        index  - The index of the element to retrieve.
    
    Returns:
        The value at the specified index, or an error code if out of bounds.
*/
int vector_get_value_at_index(Vector *vector, int index);

/*
    Function: vector_print
    
    Prints the entirety of the vector.

    Parameters:
        vector - Pointer to the Vector instance.
*/
void vector_print(Vector *vector);

#endif // VECTOR_H