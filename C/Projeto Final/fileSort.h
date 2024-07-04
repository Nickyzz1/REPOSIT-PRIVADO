#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char nickName[15];
    int pontuation;
};

// Função de comparação para struct Player (por pontuação)
int comparePlayers(const void *a, const void *b) {
    const struct Player *playerA = (const struct Player *)a;
    const struct Player *playerB = (const struct Player *)b;
    return (playerA->pontuation - playerB->pontuation);
}

// Função de ordenação por Insertion Sort para struct Player
void insertionSort(struct Player *players, int numPlayers, int (*compare)(const void *, const void *)) {
    int i, j;
    struct Player key;

    for (i = 1; i < numPlayers; i++) {
        key = players[i];
        j = i - 1;

        // Move os elementos do array que são maiores que key para uma posição à frente de sua posição atual
        while (j >= 0 && compare(&players[j], &key) > 0) {
            players[j + 1] = players[j];
            j = j - 1;
        }
        players[j + 1] = key;
    }
}

// Função auxiliar para exibir os jogadores
void displayPlayers(struct Player *players, int numPlayers) {
    printf("RANKING:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].nickName, players[i].pontuation);
    }
}