#include <stdio.h>
#include <stdlib.h>

struct Responsavel{
    char name[15];
    char lastName[20];
    int birth;
    char cpf[30];
};

struct Aluno{
    char name[15];
    char lastName[20];
    int birth; //pela data de nascimnento
    struct Responsavel responsavel;
};

struct Aluno * add(struct Aluno * arr, int * n, int toAdd)
{
    // FILE *file;
    // file = fopen("Students.txt", "w");
    // fputs(file, "aaaa");
    // fprintf(file, "aaaaa");

    int year;
    int born;
    for(int i = 0; i < toAdd; i++)
    {
        printf("\nEnter a name %i: ", i);
        scanf("%s", arr[i].name);
        printf("\nEnter a last name %i: ", i);
        scanf("%s", arr[i].lastName);
        printf("\nEnter a born data %i: ", i);
        scanf("%d", &year);
        born = 2024 - year;
        arr[i].birth = born;
        printf("%s", "\n");
        printf("\nEnter the name of responsable %i: ", i);
        scanf("%s", arr[i].responsavel.name);
        printf("\nEnter a last name of responsable %i: ", i);
        scanf("%s", arr[i].responsavel.lastName);
        printf("\nEnter a born data %i: ", i);
        scanf("%d", &year);
        born = 2024 - year;
        arr[i].responsavel.birth = born;
        printf("\nEnter a cpf %i: ", i);
        scanf("%s", arr[i].responsavel.cpf);
        printf("%s", "\n");
    }
    *n += toAdd;
    return arr;
}

int main()
{
    int n;
    int toAdd;
    printf("Enter how many students you want to add:");
    scanf("%d", &toAdd);
    struct Aluno *arr = (struct Aluno*)malloc(sizeof(struct Aluno)*(n + toAdd));

    printf("\nNow let go to add the students");
    add(arr, &n, toAdd);

    printf("\n==============FILE================\n");

    for(int i = 0; i < n; i++)
    {
        //printf("\nficha:");
        printf("\nThe student name %i: %s", i, arr[i].name);
        printf("\nThe student last name %i: %s", i, arr[i].lastName);
        printf("\nThe student age %i: %i", i, arr[i].birth);
        printf("\nThe students name responsable %i: %s", i, arr[i].responsavel.name);
        printf("\nThe students last name responsable %i: %s", i, arr[i].responsavel.lastName);
        printf("\nThe students responsable age %i: %i", i, arr[i].responsavel.birth);
        printf("\nThe students responsable cpf %i: %s", i, arr[i].responsavel.cpf);
        printf("%s", "\n");
    }
    free(arr);
}

//free

// Faça um programa para uma escola que leia informações de alunos de uma escola, onde as seguintes informações são necessárias:

// Aluno:
// Nome
// Sobrenome
// Idade(Calculada pela data de nascimento)
// Responsável

// Responsável
// Nome
// Sobrenome
// Idade(Calculada pela data de nascimento)
// CPF

// Imprima uma ficha do aluno cadastrado dentro de um arquivo.

