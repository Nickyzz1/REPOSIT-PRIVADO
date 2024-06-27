#include <stdio.h>
#include <stdlib.h>

void appendToFile(const char *filename, const char *name, int score) {
    FILE *file = fopen(filename, "a"); // "a" abre o arquivo para escrita no final (append)
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "%s %d\n", name, score); // Escreve o nome e a pontuação no arquivo
    fclose(file); // Fecha o arquivo
}

void printFileContents(const char *filename) {
    FILE *file = fopen(filename, "r"); // "r" abre o arquivo para leitura
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    printf("Contents of the file %s:\n", filename);
    char line[256]; // Buffer para ler cada linha do arquivo

    // Lê e imprime cada linha do arquivo
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file); // Fecha o arquivo
}

int main() {
    const char *filename = "pontuation.txt";
    char playerName[20];
    int playerScore;

    printf("Enter the player's nickname: ");
    scanf("%s", playerName);

    printf("Enter the player's score: ");
    scanf("%d", &playerScore);

    // Adiciona o nome e a pontuação do jogador ao arquivo
    appendToFile(filename, playerName, playerScore);

    // Imprime o conteúdo atualizado do arquivo
    printFileContents(filename);

    return 0;
}
