#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int xEnemy = 0;
int yEnemy = 0;
int xCharc = 0;
int yCharc = 0;

int l = 9;
int c = 15;

int enemy = 9;
int prota = 10;

//int * positionEnemy = matriz[xEnemy][yCharc];
//cima é l - 1 e c
//baixo é l + 1 e c
//esquerda é l e c +1
//direira é l e c - 1
void top(int matriz[9][15], int * positionEnemy)
{
    xEnemy --;
    *positionEnemy = matriz[xEnemy][xCharc];
}

void low(int matriz[9][15], int * positionEnemy)
{
    xEnemy ++;
    *positionEnemy = matriz[xEnemy][xCharc];
}

void left(int matriz[9][15], int * positionEnemy)
{
    xCharc ++;
    *positionEnemy = matriz[xEnemy][xCharc];
}

void right(int matriz[9][15], int * positionEnemy)
{
    xCharc --;
    *positionEnemy = matriz[xEnemy][xCharc];
}

void generatePosition(int matriz[9][15], int xEnemy, int yEnemy, int xCharc, int yCharc) {
    srand(time(NULL));
    yEnemy = rand() % 15;
    xEnemy = rand() % 9;
    yCharc = rand() % 15;
    xCharc = rand() % 9;

    matriz[xEnemy][yEnemy] = enemy;
    matriz[xCharc][yCharc] = prota;

    printf("\nstart enemy line: %i, start enemy col: %i, final porta line: %i, final col: %i\n", xEnemy, yEnemy, xCharc, yCharc);
}
void moverEnemys(int matriz[9][15])
{
    int randArr[4] = {1,2,3,4};
    int * positionEnemy = matriz[xEnemy][yCharc];
    int * positionCharc = matriz[xCharc][yCharc];
    while(positionEnemy != positionCharc)
    {
        srand(time(NULL));
        int randomMov = rand() % 5;
        usleep(100000); // 100000 microssegundos = 0.1 segundos
        if()
        {
            top(matriz, &positionEnemy);
        }
        else if()
        {
            low(matriz, &positionEnemy);
        }
         else if()
        {
            left(matriz, &positionEnemy);   
        }
         else if()
        {
            right(matriz, &positionEnemy);
        }

    }


}
//cima é l - 1 e c
//baixo é l + 1 e c
//esquerda é l e c +1
//direira é l e c - 1


// void pathFider(int matriz)
// {
//     //idf parede == 1 nn pode atravessar
//     //para o lado: o lado dele é zero? pode: não pode
//     //preciso que os enimigos vão para lugares a aleatórios
//     //preciso de acoirdo commo moviment9o d0o personagem e o apertar do ewspaço os lugartes na matrzi sejam ocupados
//     //enimigos quando voirarem explosão devem sumir



// }

void displayMatriz(int matriz[9][15]) {
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

    generatePosition(matriz, xEnemy,  yEnemy,  xCharc,  yCharc);
    displayMatriz(matriz);
}
