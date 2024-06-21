#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int enemy = 9;
int prota = 10;

void generatePosition(int matriz[9][15], int xStart, int yStart, int xEnd, int yEnd) {
    srand(time(NULL));
    yStart = rand() % 15;
    xStart = rand() % 9;
    yEnd = rand() % 15;
    xEnd = rand() % 9;

    matriz[xStart][yStart] = enemy;
    matriz[xEnd][yEnd] = prota;

    printf("\nstart col: %i, start line: %i, final col: %i, final line: %i\n", xStart, yStart, xEnd, yEnd);
}

void pathFider(int matriz)
{
    //preciso que os enimigos vão para lugares a aleatórios
    //preciso de acoirdo commo moviment9o d0o personagem e o apertar do ewspaço os lugartes na matrzi sejam ocupados
    //enimigos quando voirarem explosão devem sumir


}

void displayMatriz(int matriz[9][15], int l, int c) {
    printf("%s", "\n");
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("%i, ", matriz[i][j]);
        }
        printf("%s", "\n");
    }
}



int main() 
{
    int xStart = 0;
    int yStart = 0;
    int xEnd = 0;
    int yEnd = 0;

    int l = 9;
    int c = 15;

    int matriz[9][15] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    generatePosition(matriz, xStart,  yStart,  xEnd,  yEnd);
    displayMatriz(matriz, l, c);
}
