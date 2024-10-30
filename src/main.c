#include <stdio.h>
#include "vector.h"

int main(){
    Vector my_vector;

    if(vector_init(&my_vector, 10) != 0){
        return 1;
    }

    vector_push_back(&my_vector, 5);

    vector_print(&my_vector);
    
    free(my_vector.data);

    return 0;
}