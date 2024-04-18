#include <stdio.h>
#include <stdlib.h>
// Faça um programa que leia o tamanho de um vetor de inteiros e reserve
// dinamicamente memoria para esse
// vetor. Em seguida, leia os elementos
// desse vetor, imprima o vetor lido e mostre o resultado da soma dos numeros
// ımpares presentes no vetor
int main(){
    int adc;
    // int num;
    int sum=0;
    printf("enter how many numbers you wanna adc: ");
    scanf("%i", &adc);
    int *array = (int *)malloc(adc * sizeof(int));
    for(int i =0; i<adc;i++){
        printf("Enter a number: ");
        scanf("%i", &array[i]);
    }
    printf("The list: ");
    for(int j = 0; j<adc;j++){
            printf("%i,", array[j]);
            if(array[j]%2!=0){
                sum+= array[j];
        }
        }
    printf("\nThe sum :%i", sum);
}
