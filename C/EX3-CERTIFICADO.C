#include <stdio.h>

int main(){
    char name[100];
    char sob[100];
    char cpf[12];
    char datab[10];

    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Enter your last name: ");
    scanf("%s", &sob);
    printf("Enter youf CPF: ");
    scanf("%s", &cpf);
    printf("Enter your birth date: ");
    scanf("%s", &datab);

    printf("O aluno: %s %s, nascido no dia: %s de CPF: %s cumpriu com todos os requisitos para formar-se na ETS!", name, sob,datab,cpf);

    return 0;
}
