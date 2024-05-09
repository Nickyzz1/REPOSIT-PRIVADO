#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int idade;
}Pessoa;

int main(){
    Pessoa * p1,* p2;

    strcpy(p1->nome,"Nicolle");
    p1->idade = 18;  

    p2 = malloc(10 * sizeof(Pessoa));

    free(p2);
}
