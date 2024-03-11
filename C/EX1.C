#include <stdio.h>

int main(){
    float n1;
    float n2;
    float n3;
    printf("ENTER YOUR GRADE FOR 1 QUARTER: ");
    scanf("%f", &n1);
    printf("ENTER YOUR GRADE FOR 2 QUARTER: ");
    scanf("%f", &n2);
    printf("ENTER YOUR GRADE FOR 3 QUARTER: ");
    scanf("%f", &n3);
    float med = (n1*2+n2*3+n3*5)/10;
    printf("%f", med);
    return 0;
}

// a letra que vem depois do % representa que tipo de dado, é, quando é i vem um inteiro, quando é s vem um char str, quando é um f vem um float
