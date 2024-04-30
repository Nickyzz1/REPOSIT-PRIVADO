#include <stdio.h>
// //Implementar uma função que receba dois valores e utilize ponteiros para
// trocar o valor das variáveis. Defina um valor inicial e exiba o valor inicial e
// o valor após a alteração.


int main(){
    int * pprt;
    int * pprt2;
    int num1 = 10;
    int num2= 0;

    pprt = &num1;
    pprt2 = &num2;
  
    printf("Enter the first number: ");
    scanf("%i", &num1);
    printf("Enter the second number: ");
    scanf("%i", &num2);  

    printf("number 1 = %i\nnumber 2 = %i", num1, num2);
    printf("\nadress of number 1: %i", &num1);
    printf("\nadress of number 1: %i", &num2);
    printf("\nadress of pointer number 1: %i", pprt); //pprt mostra o endereço apontado e o &pprt mostra o endereço da variável ponteiro
    printf("\nadress of pointer number 1: %i", pprt2); 
    printf("\nvalue1: %i", *pprt); 
    printf("\nvalue2: %i", *pprt2); 
}
