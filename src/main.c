#include <stdio.h>
#include "vector.h"

int main(){
    Vector my_vector;

    if(initialise_vector(&my_vector, sizeof(int), 10) != 0){
        return 1;
    }
    
    free(my_vector.data);

    return 0;
}