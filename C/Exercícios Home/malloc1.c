#include <stdio.h> 
#include <stdlib.h>
//faça uma função que receba duas matrizes e aloque memória para uma matriz resultado;

int **alloc(int matriz1[][3], int matriz2[][3]) //função que aloca memória para a matriz resultado e soma as matrizes
{
    int **matriz3 = malloc(sizeof(int*)*3); //criando matriz resultado
    for(int i = 0; i<3;i++)
    {
        matriz3[i] = (int*)malloc(sizeof(int)*3);
    }
    for(int j = 0; j<3;j++) //somando matrizes num item
    { 
        for(int k = 0; k<3;k++) 
        {
            matriz3[j][k] = matriz1[j][k] + matriz2[j][k]; 
        }
    }
    return matriz3;
}

int main(){ 
    int matriz1[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };

    int matriz2[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };

    int ** soma = alloc(matriz1,matriz2);
    for(int j = 0; j<3;j++)
    {
        for(int k = 0; k<3;k++)
        {
            printf("[%d]", soma[j][k]);
        }
        printf("%s", "\n");
    }
    for(int j = 0; j < 3; j++) // Liberando memória
    {
        free(soma[j]);
    }
    free(soma);
}
