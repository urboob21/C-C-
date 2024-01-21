#include "stdio.h"
#include "malloc.h"

int main(){
    int size;
    scanf( "%d",&size);
    int *array = malloc(sizeof(int)*size);
    for(int i = 0 ; i< size; i++){
        array[i] = i;
        printf("%d \n",array[i]);
    }
    
    free(array);


    return 0;
}