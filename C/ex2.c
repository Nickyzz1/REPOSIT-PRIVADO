#include <stdio.h>

int main(){
    int num = 10;
    int *pprt;
    pprt = &num;
    printf("The number: %i\nthe adress of point: %i\nthe adress of the number: %i", *pprt, &pprt, &num); 
}