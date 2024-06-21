
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

void generatePosition(int matriz[9][15], int *xEnemy, int *yEnemy, int *xCharc, int *yCharc) {
    srand(time(NULL));
    *yEnemy = rand() % 15;
    *xEnemy = rand() % 9;
    *yCharc = rand() % 15;
    *xCharc = rand() % 9;

    matriz[*xEnemy][*yEnemy] = enemy;
    matriz[*xCharc][*yCharc] = prota;

    printf("\nstart enemy line: %i, start enemy col: %i, final porta line: %i, final col: %i\n", *xEnemy, *yEnemy, *xCharc, *yCharc);
}

void top(int matriz[9][15], int *xEnemy)
{
    if (*xEnemy > 0) {
        matriz[*xEnemy][yEnemy] = 0;
        (*xEnemy)--;
        matriz[*xEnemy][yEnemy] = enemy;
    }
}

void low(int matriz[9][15], int *xEnemy)
{
    if (*xEnemy < l - 1) {
        matriz[*xEnemy][yEnemy] = 0;
        (*xEnemy)++;
        matriz[*xEnemy][yEnemy] = enemy;
    }
}

void left(int matriz[9][15], int *yEnemy)
{
    if (*yEnemy > 0) {
        matriz[xEnemy][*yEnemy] = 0;
        (*yEnemy)--;
        matriz[xEnemy][*yEnemy] = enemy;
    }
}

void right(int matriz[9][15], int *yEnemy)
{
    if (*yEnemy < c - 1) {
        matriz[xEnemy][*yEnemy] = 0;
        (*yEnemy)++;
        matriz[xEnemy][*yEnemy] = enemy;
    }
}

void displayMatriz(int matriz[9][15]) {
    printf("%s", "\n");
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("%i, ", matriz[i][j]);
        }
        printf("%s", "\n");
    }
}

void moverEnemys(int matriz[9][15])
{
    while(1)
    {
        if(matriz[xCharc][yCharc] == matriz[xEnemy][yEnemy])
        {
            printf("you lose\n");
            break;
        }
        else
        {
            srand(time(NULL));
            int randomMov = rand() % 4;
            usleep(100000); // 100000 microssegundos = 0.1 segundos
            if(randomMov == 0)
            {
                top(matriz, &xEnemy);
            }
            else if(randomMov == 1)
            {
                low(matriz, &xEnemy);
            }
            else if(randomMov == 2)
            {
                left(matriz, &yEnemy);   
            }
            else if(randomMov == 3)
            {
                right(matriz, &yEnemy);
            }
            displayMatriz(matriz);
        }
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

    generatePosition(matriz, &xEnemy, &yEnemy, &xCharc, &yCharc);
    displayMatriz(matriz);
    moverEnemys(matriz);

    return 0;
}




// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <unistd.h>

// int xEnemy = 0;
// int yEnemy = 0;
// int xCharc = 0;
// int yCharc = 0;

// int l = 9;
// int c = 15;

// int enemy = 9;
// int prota = 10;

// // enemy= matriz[xEnemy][yEnemy];
// // matriz[xCharc][yCharc] = prota;

// //int * positionEnemy = matriz[xEnemy][yCharc];
// //cima é l - 1 e c
// //baixo é l + 1 e c
// //esquerda é l e c +1
// //direira é l e c - 1
// void top(int matriz[9][15], int *xEnemy)
// {
//     *xEnemy --;
//     //*positionEnemy = matriz[xEnemy][xCharc];
// }

// void low(int matriz[9][15],int *xEnemy)
// {
//     *xEnemy ++;
//     //*positionEnemy = matriz[xEnemy][xCharc];
// }

// void left(int matriz[9][15],int *yEnemy)
// {
//     *yEnemy ++;
//     //*positionEnemy = matriz[xEnemy][xCharc];
// }

// void right(int matriz[9][15],int *yEnemy)
// {
//     *yEnemy --;
//     //*positionEnemy = matriz[xEnemy][xCharc];
// }

// // void generatePosition(int matriz[9][15], int xEnemy, int yEnemy, int xCharc, int yCharc) {
// //     srand(time(NULL));
// //     yEnemy = rand() % 15;
// //     xEnemy = rand() % 9;
// //     yCharc = rand() % 15;
// //     xCharc = rand() % 9;

// //     matriz[xEnemy][yEnemy] = enemy;
// //     matriz[xCharc][yCharc] = prota;

// //     printf("\nstart enemy line: %i, start enemy col: %i, final porta line: %i, final col: %i\n", xEnemy, yEnemy, xCharc, yCharc);
// // }
// // void updatePosition(int matriz[9][15], int xEnemy, int yEnemy, int xCharc, int yCharc)
// // {

// // }
// void moverEnemys(int matriz[9][15])
// {
//     int randArr[4] = {1,2,3,4};
//     int * positionEnemy = matriz[xEnemy][yCharc];
//     int * positionCharc = matriz[xCharc][yCharc];
//     while(1)
//     {
//         if(positionCharc == positionEnemy)
//         {
//             printf("you lose");

//         }
//         else
//         {
//             srand(time(NULL));
//             int randomMov = rand() % 5;
//             usleep(100000); // 100000 microssegundos = 0.1 segundos
//             if(randomMov == 1)
//             {
//                 top(matriz, &xEnemy);
//             }
//             else if(randomMov == 2)
//             {
//                 low(matriz, &xEnemy);
//             }
//             else if(randomMov == 3)
//             {
//                 left(matriz, &yEnemy);   
//             }
//             else if(randomMov == 4)
//             {
//                 right(matriz, &yEnemy);
//             }
//             displayMatriz(matriz);
//         }
//     }
// }
// //cima é l - 1 e c
// //baixo é l + 1 e c
// //esquerda é l e c +1
// //direira é l e c - 1


// // void pathFider(int matriz)
// // {
// //     //idf parede == 1 nn pode atravessar
// //     //para o lado: o lado dele é zero? pode: não pode
// //     //preciso que os enimigos vão para lugares a aleatórios
// //     //preciso de acoirdo commo moviment9o d0o personagem e o apertar do ewspaço os lugartes na matrzi sejam ocupados
// //     //enimigos quando voirarem explosão devem sumir
// // }

// void displayMatriz(int matriz[9][15]) {
//     printf("%s", "\n");
//     for(int i = 0; i < l; i++) {
//         for(int j = 0; j < c; j++) {
//             printf("%i, ", matriz[i][j]);
//         }
//         printf("%s", "\n");
//     }
// }

// int main() 
// {
//     int matriz[9][15] = {
//         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//     };

//     yEnemy = rand() % 15;
//     xEnemy = rand() % 9;
//     yCharc = rand() % 15;
//     xCharc = rand() % 9;

//     while(1)
//     {
//         moverEnemys(matriz);
//     }
// }
