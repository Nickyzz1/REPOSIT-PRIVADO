#include <stdio.h>
#include <stdlib.h>

void appendToFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a"); // "a" abre o arquivo para escrita no final (append)
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "%s\n", data); // Escreve a string data no arquivo
    fclose(file); // Fecha o arquivo
}

void printFileContents(const char *filename) {
    FILE *file = fopen(filename, "r"); // "r" abre o arquivo para leitura
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    printf("Contents of the file %s:\n", filename);
    char line[256]; // lê cada linha do arquivo

    // Lê e imprime cada linha do arquivo
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file); // Fecha o arquivo
}

int main() {
    const char *filename = "pontuation.txt";
    char newPlayer[20];

    printf("Enter the name of the new player: ");
    scanf("%s", newPlayer);

    // Adiciona o novo jogador ao arquivo
    appendToFile(filename, newPlayer);

    // Imprime o conteúdo atualizado do arquivo
    printFileContents(filename);

    return 0;
}
