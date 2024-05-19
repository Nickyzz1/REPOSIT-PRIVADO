#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct
struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    int numPessoas;

    // Pergunta ao usuário quantas pessoas deseja cadastrar
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &numPessoas);

    // Alocação dinâmica de memória para um array de structs Pessoa
    struct Pessoa *pessoas = (struct Pessoa *)malloc( sizeof(struct Pessoa)* numPessoas);

    // Verificação se a alocação foi bem-sucedida
    if (pessoas == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Leitura dos dados das pessoas
    for (int i = 0; i < numPessoas; i++) {
        printf("Nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", pessoas[i].nome);  // Leitura do nome com espaços
        printf("Idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }

    // Impressão dos dados das pessoas
    printf("\nLista de Pessoas:\n");
    for (int i = 0; i < numPessoas; i++) {
        printf("Pessoa %d: Nome = %s, Idade = %d\n", i + 1, pessoas[i].nome, pessoas[i].idade);
    }

    // Liberação da memória alocada
    free(pessoas);

    return 0;
}
