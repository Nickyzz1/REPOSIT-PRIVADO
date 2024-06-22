#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para usleep em sistemas Unix-like
// #include <windows.h> // Se estiver no Windows

int xEnemy = 0;
int yEnemy = 0;
int xCharc = 0;
int yCharc = 0;

int l = 9;
int c = 15;

int enemy = 9;
int prota = 10;

void clearWin() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void generatePosition(int matriz[9][15], int *xEnemy, int *yEnemy, int *xCharc, int *yCharc) {
    srand(time(NULL));
    *xEnemy = rand() % 9;
    *yEnemy = rand() % 15;
    *xCharc = rand() % 9;
    *yCharc = rand() % 15;

    matriz[*xEnemy][*yEnemy] = enemy;
    matriz[*xCharc][*yCharc] = prota;

    printf("Inimigo: linha %d, coluna %d\n", *xEnemy, *yEnemy);
    printf("Personagem: linha %d, coluna %d\n", *xCharc, *yCharc);
}

void displayMatriz(int matriz[9][15]) {
    clearWin();
    printf("\n");
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void moveEnemys(int matriz[9][15]) {
    while (1) {
        // Verifica se o inimigo alcançou o personagem
        if (matriz[xCharc][yCharc] == matriz[xEnemy][yEnemy]) {
            printf("Você perdeu!\n");
            break;
        } else {
            // Gera um movimento aleatório para o inimigo
            int randomMov = rand() % 4;

            // Atraso entre os movimentos
            sleep(2); // Espera 2 segundos entre cada movimento

            // Limpa a posição atual do inimigo na matriz
            matriz[xEnemy][yEnemy] = 0;

            // Aplica o movimento aleatório, garantindo que seja para uma posição adjacente válida
            if (randomMov == 0 && xEnemy > 0 && (matriz[xEnemy - 1][yEnemy] == 0 || matriz[xEnemy - 1][yEnemy] == 10)) { // Movimento para cima
                xEnemy--;
            } else if (randomMov == 1 && xEnemy < l - 1 && (matriz[xEnemy + 1][yEnemy] == 0 || matriz[xEnemy + 1][yEnemy] == 10)) { // Movimento para baixo
                xEnemy++;
            } else if (randomMov == 2 && yEnemy > 0 && (matriz[xEnemy][yEnemy - 1] == 0 || matriz[xEnemy][yEnemy - 1] == 10)) { // Movimento para a esquerda
                yEnemy--;
            } else if (randomMov == 3 && yEnemy < c - 1 && (matriz[xEnemy][yEnemy + 1] == 0 || matriz[xEnemy][yEnemy + 1] == 10)) { // Movimento para a direita
                yEnemy++;
            }

            // Atualiza a posição do inimigo na matriz
            matriz[xEnemy][yEnemy] = enemy;

            // Mostra a matriz atualizada
            displayMatriz(matriz);
        }
    }
}

int main() {
    int matriz[9][15] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    generatePosition(matriz, &xEnemy, &yEnemy, &xCharc, &yCharc);
    displayMatriz(matriz);
    moveEnemys(matriz);

    return 0;
}

