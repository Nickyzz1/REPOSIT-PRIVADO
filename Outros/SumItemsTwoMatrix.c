#include <stdio.h>
//Crie um programa que leia duas matrizes três por dois. Você deverá somar as duas matrizes e exibir as matrizes originais, e o resultado.
int main(){

    int matriz1[3][2] ={
        {1,2},
        {4,5},
        {7,8}
    };
    for(int i =0; i<3; i++){
        int soma1=0;
        for(int j=0; j<2; j++){
            soma1+= matriz1[i][j];
        }
    int matriz2[3][2] = {
    {10,10},
    {10,10},
    {10,10}
    };
    int soma2 =0;
        for(int j=0; j<2; j++){
            soma2+= matriz2[i][j];
        }
        soma2+=soma1;
        printf("%i\n", soma2);
    }
}
