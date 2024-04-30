#include <stdio.h>
// - Faça um programa que calcule a média de notas de alunos. cada linha corresponde a média de  um aluno
// diferente e a coluna são suas notas
int main(){
    int matriz[3][3] =
    {
        {8, 7, 10},
        {2,5,7},
        {10,10,10}
    };
    for(int i =0; i<3;i++){
        int mean=0;
        for(int j = 0; j<3; j++){
            mean += matriz[i][j];
        }
        printf("The mean is:%i\n", mean/3);
        }
        
}

