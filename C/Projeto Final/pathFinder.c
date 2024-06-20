#include <stdio.h> // rand é da stdlib
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_NUMBERS 143

//thats define poisitions for two numbers, the start and the destany
void generatePosition(int **matriz)
{
    srand(time(NULL));
    int YStart = rand() % 13;
    int XStart = rand() % 13;
    int YFinal = rand() % 13;
    int XFinal = rand() % 13;

    matriz[XStart][YStart] = 9;
    matriz[XFinal][YFinal] = 10;
    
    printf("\nstart col: %i, start line:  %i, final col: %i, final line %i", YStart, XStart, YFinal, XFinal);
}

void generateArena(int **matriz)
{
    int position;
    int count;

    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(matriz[i][j] != 9 && matriz[i][j] != 10)
            {
                position = rand() % 2;
                matriz[i][j] = position;
                count += 1;
            }
        }
    }
}

void displayMatriz(int **matriz)
{
    printf("%s", "\n");
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            printf("%i, ",matriz[i][j]);
        }
        printf("%s", "\n");
    }
}


int main()
{
    int **matriz = malloc(sizeof(int)*12);
    for(int i = 0; i < 12; i++)
    {
        matriz[i] = malloc(sizeof(int)*12);
    }
    // colocando valores iniciais poara a matriz
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            matriz[i][j] = 0;
        }
    }

    generatePosition(matriz);
    generateArena(matriz);
    displayMatriz(matriz);

    // li'berando memória
    for(int i = 0; i < 12; i++)
    {
        free(matriz);
        for(int j = 0; j < 12; j++)
        {
            free(matriz);
        }
    }

    // {
    //     {9,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1},
    //     {1,0,0,0,1,1,1,0,0,0,1,1}
    // };

//     for(int i = 0; i < 12; i++)
//     {
//         for(int j = 0; j < 12; j++)
//         {
//             free(matriz[i][j]);
//         }
//     }
}




// // Definição das constantes do jogo
// #define BOARD_SIZE 10
// #define MAX_ENEMIES 15

// // Enumeração para as direções de movimento
// typedef enum {
//     UP,
//     DOWN,
//     LEFT,
//     RIGHT
// } Direction;

// // Estrutura para representar o jogador e os inimigos
// typedef struct {
//     int x, y;  // Posição no tabuleiro
// } Character;

// // Função para inicializar o tabuleiro do jogo
// void initialize_board(char board[BOARD_SIZE][BOARD_SIZE], Character *player, Character enemies[MAX_ENEMIES]) {
//     // Preencher o tabuleiro com espaços vazios
//     for (int i = 0; i < BOARD_SIZE; ++i) {
//         for (int j = 0; j < BOARD_SIZE; ++j) {
//             board[i][j] = ' ';
//         }
//     }

//     // Posicionar o jogador no canto superior esquerdo
//     player->x = 0;
//     player->y = 0;
//     board[player->x][player->y] = 'P';

//     // Posicionar inimigos aleatoriamente no tabuleiro
//     srand(time(NULL));
//     for (int i = 0; i < MAX_ENEMIES; ++i) {
//         enemies[i].x = rand() % BOARD_SIZE;
//         enemies[i].y = rand() % BOARD_SIZE;
//         board[enemies[i].x][enemies[i].y] = 'E';
//     }
// }

// // Função para imprimir o tabuleiro
// void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
//     for (int i = 0; i < BOARD_SIZE; ++i) {
//         for (int j = 0; j < BOARD_SIZE; ++j) {
//             printf("%c ", board[i][j]);
//         }
//         printf("\n");
//     }
// }

// // Função para mover o jogador
// void move_player(Character *player, Direction dir) {
//     switch (dir) {
//         case UP:
//             if (player->x > 0) player->x--;
//             break;
//         case DOWN:
//             if (player->x < BOARD_SIZE - 1) player->x++;
//             break;
//         case LEFT:
//             if (player->y > 0) player->y--;
//             break;
//         case RIGHT:
//             if (player->y < BOARD_SIZE - 1) player->y++;
//             break;
//     }
// }

// // Função para mover um inimigo aleatoriamente
// void move_enemy(Character *enemy) {
//     Direction dir = rand() % 4;
//     switch (dir) {
//         case UP:
//             if (enemy->x > 0) enemy->x--;
//             break;
//         case DOWN:
//             if (enemy->x < BOARD_SIZE - 1) enemy->x++;
//             break;
//         case LEFT:
//             if (enemy->y > 0) enemy->y--;
//             break;
//         case RIGHT:
//             if (enemy->y < BOARD_SIZE - 1) enemy->y++;
//             break;
//     }
// }

// // Função principal do jogo
// int main() {
//     char board[BOARD_SIZE][BOARD_SIZE];
//     Character player;
//     Character enemies[MAX_ENEMIES];

//     initialize_board(board, &player, enemies);

//     // Loop principal do jogo
//     while (true) {
//         // Limpar a tela (para sistemas UNIX-like)
//         system("clear");

//         // Imprimir o tabuleiro
//         print_board(board);

//         // Ler o movimento do jogador
//         printf("Digite o movimento (WASD para cima, baixo, esquerda, direita): ");
//         char move;
//         scanf(" %c", &move);

//         // Movimentar o jogador
//         switch (move) {
//             case 'W':
//                 move_player(&player, UP);
//                 break;
//             case 'S':
//                 move_player(&player, DOWN);
//                 break;
//             case 'A':
//                 move_player(&player, LEFT);
//                 break;
//             case 'D':
//                 move_player(&player, RIGHT);
//                 break;
//         }

//         // Movimentar os inimigos
//         for (int i = 0; i < MAX_ENEMIES; ++i) {
//             move_enemy(&enemies[i]);
//         }

//         // Verificar colisões e outras condições de jogo (não implementado neste exemplo)

//         // Simular atraso para visualização (apenas para efeitos visuais no terminal)
//         for (int i = 0; i < 100000000; ++i) {}

//         // Fim de jogo (não implementado neste exemplo)

//     }

//     return 0;
// }
