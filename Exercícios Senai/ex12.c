#include <stdio.h>

int main(){
    int array[] = {1,2,3,4,5};
    int len = sizeof(array)/sizeof(array[0]);
    int * pprt;
    pprt = &array[2];
    *pprt = 10;
    for(int i = 0; i <len; i++ ){
        printf("%i, ", array[i]);
    }
}