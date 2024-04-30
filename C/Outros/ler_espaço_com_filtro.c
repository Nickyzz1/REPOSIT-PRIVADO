#include <stdio.h>
#include <stdlib.h>
// - Crie um programa para alocar memória para uma string, e permitir o usuário escrever dentro da mesma.
int main(){
    int len = 100;
    char *texto = (char*)malloc(len*sizeof(char));
    printf("Write something...: ");
    scanf("%99[^\n]", texto);
    printf("\n%s", texto);
}
