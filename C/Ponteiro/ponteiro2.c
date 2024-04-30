#include <stdio.h>

// Escreva um programa que contenha uma função que receba dois valores
// inteiros. Leia esses valores do teclado. Em seguida, compare seus
// endereços e exiba o conteúdo do maior endereço.

void valores(int num1, int num2){
    int *pprt;
    int *pprt2;

    pprt = &num1;
    pprt2 = &num2;

    if(pprt > pprt2){
        printf("Adress number 1 is bigger then number 2: ");
        printf("%i, %i", pprt, pprt2);
    }
    else if(pprt < pprt2){
        printf("Adress number 2 is bigger then number 1: ");
        printf("%i, %i", pprt, pprt2);
    }
    else{
        printf("error!");
    }
}
    
int main(){

    int num1=0;
    int num2=0;

    printf("Enter number 1: ");
    scanf("%i", &num1);
    printf("Enter number 2: ");
    scanf("%i", &num2);
    valores(num1, num2);

}
