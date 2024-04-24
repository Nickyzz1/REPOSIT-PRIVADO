#include <stdio.h>
// - Programa que leia a quantidade de valores que o usuário deseja inserir dentro de um array e o permitia inserir estes valores.

int main(){
    int len;
    int num;
    printf("Enter how many items you wanna adc on array:");
    scanf("%i", &len);
    int *array = (int *)malloc(len*sizeof(int));
    for(int i=0; i<len; i++){
        printf("Enter a number: ");
        scanf("%i", &num);
        array[i]=num;
    }
    for(int i=0; i<len; i++){
        printf("%i,", array[i]);
    }

}
