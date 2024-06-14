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
    int year;
    int born;
    for(int i = 0; i < toAdd; i++)
    {
        printf("\nEnter a name: ");
        scanf("%s", arr[i].name);
        printf("\nEnter a last name: ");
        scanf("%s", arr[i].lastName);
        printf("\nEnter a born data: ");
        scanf("%d", &year);
        born = 2024 - year;
        arr[i].birth = born;
        printf("%s", "\n");
        printf("\nEnter the name of responsable: ");
        scanf("%s", arr[i].responsavel.name);
        printf("\nEnter a last name of responsable: ");
        scanf("%s", arr[i].responsavel.lastName);
        printf("\nEnter a born data: ");
        scanf("%d", &year);
        born = 2024 - year;
        arr[i].responsavel.birth = born;
        printf("\nEnter a cpf: ");
        scanf("%s", arr[i].responsavel.cpf);
    }
    *n += toAdd;
    return arr;
}

// void display(struct Aluno * arr, int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         printf("\nThe student name: %s", arr[i].name);
//         printf("\nThe student last name: %s", arr[i].lastName);
//         printf("\nThe student age: %i", arr[i].birth);
//         printf("\nThe students name responsable: %s", arr[i].responsavel.name);
//         printf("\nThe students last name responsable: %s", arr[i].responsavel.lastName);
//         printf("\nThe students responsable age: %i", arr[i].responsavel.birth);
//         printf("\nThe students responsable cpf: %s", arr[i].responsavel.cpf);
//         printf("%s", "\n");
//     }
// }

int main()
{
    int n;
    int toAdd;
    printf("Enter how many students you want to add:");
    scanf("%d", &toAdd);
    struct Aluno *arr = (struct Aluno*)malloc(sizeof(struct Aluno)*(n + toAdd));
    int option;

    while(1)
    {
        printf("\n======================\n");
        printf("\n0 - exit ======================\n");
        printf("\n1 - add student ======================\n");
        printf("\n2 - display(ficha)======================\n");
        scanf("%d", &option);

        if(option == 0)
        {
            break;
        }
        else if(option == 1)
        {
            printf("\nNow let go to add the students");
            add(arr, &n, toAdd);
        }
        else if(option == 2)
        {
            for(int i = 0; i < n; i++)
            {
                printf("\nThe student name: %s", arr[i].name);
                printf("\nThe student last name: %s", arr[i].lastName);
                printf("\nThe student age: %i", arr[i].birth);
                printf("\nThe students name responsable: %s", arr[i].responsavel.name);
                printf("\nThe students last name responsable: %s", arr[i].responsavel.lastName);
                printf("\nThe students responsable age: %i", arr[i].responsavel.birth);
                printf("\nThe students responsable cpf: %s", arr[i].responsavel.cpf);
                printf("%s", "\n");
            }
        }
        else
        {
            printf("Enter a valid option");

        }
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

