#include <stdio.h>
#include <stdlib.h>

// 4 - Aloque memória para uma matriz. O usuário decide quantas linhas e quantas colunas devem existir.

int main(){
    int l;
    int c;
    int temp;
    printf("-----VAMOS CRIAR UMA MATRIZ-----");
    printf("\nHow many lines you want to add: ");
    scanf("%i", &l);
    printf("\nHow many columns you want to add: ");
    scanf("%i", &c);
    int **matriz = malloc(sizeof(int*)*l);
    for(int i=0;i<l;i++){
        matriz[i] = (int *)malloc(sizeof(int) * c);
    }
    int quant = l*c;
    for(int n=0; n<l;n++){
        for(int k=0; k<c; k++){
            printf("\nEnter a number to add into matrix: ");
            scanf("%i", &matriz[n][k]);
        }
    }
    for(int n=0; n<l;n++){
            for(int k=0; k<c; k++){
                printf("%i\n",matriz[n][k]);
}

}}
