#include <stdio.h>

typedef struct{
    char name[10];
    int registration;
    int nota1;
    int nota2;
    int nota3;

}Student;


int main() 
{
    //cria as variáveis usadas
    Student student[2];
    int  temp;
    int  meanBig;
    int  meanLow;
    int  meanStudent;
    char arrayAprovados[20][20];
    char arrayReprovados[20][20];

    //cria os 5 alunos
    for(int i = 0; i < 2; i++) 
    {
        printf("Enter a student %i: ", i );
        scanf("%s", &student[i].name);
        printf("Enter the registrationt %i: ", i );
        scanf("%d", &student[i].registration);
        printf("Enter the grade for the first test %i: ", i );
        scanf("%i", &student[i].nota1);
        printf("Enter the grade for the second test %i: ", i );
        scanf("%i", &student[i].nota2);
        printf("Enter the grade for the third test %i: ", i );
        scanf("%i", &student[i].nota3);

        //guarda a nota iterada numa var temporária
        temp = student[i].nota1;

        //condição para mudar o valor de temp
        if(student[i].nota1 > temp) 
        {
            temp = student[i].nota1;
        }

        //atribuição dos calculos das médias
        meanBig = ((student[i].nota1) * (student[i].nota2 )* (student[i].nota3))/3;
        meanLow = (student[i].nota1 * student[i].nota2 * student[i].nota3)/3;
        meanStudent = (student[i].nota1 * student[i].nota1 * student[i].nota1)/3;

        //comparação para mudar o valor do meanBig
        if(meanBig < (student[i].nota1 * student[i].nota2 * student[i].nota3)/3) 
        {
            meanBig = (student[i].nota1 * student[i].nota2 * student[i].nota3)/3;
        }
        
        //comparação para mudar o valor do meanLow
        if(meanLow > (student[i].nota1 * student[i].nota2 * student[i].nota3)/3) 
        {
            meanLow = (student[i].nota1 * student[i].nota2 * student[i].nota3)/3;
        }

        //comparação para reprovar e aprovar
        if(meanStudent >= 6) 
        {
            //adiciona a lista aprovados
            for(int j = 0; j < 2; j++) 
            {
                arrayAprovados[i][j] = student[i].name[j];
            }
        } 
        else 
        {
            //adiciona a lista reprovados
            for(int j = 0; j < 2; j++) 
            {
                arrayReprovados[i][j] = student[i].name[j];
            }
        } 
    }

    //mostra os resultados
    printf("\n\nThe biggest grade student on test 1: %i", temp);
    printf("\n\nThe biggest mean: %i", meanBig);
    printf("\n\nThe Lowest mean: %i", meanLow);

    printf("\n\nAproved:");
    for(int i = 0; i < 2; i++) 
    {
        printf("%s\n" , arrayAprovados[i]);
    }

    printf("\n\nReproved:");
    for(int i = 0; i < 2; i++) 
    {
        printf("%s" , arrayReprovados[i]);
    }

}
