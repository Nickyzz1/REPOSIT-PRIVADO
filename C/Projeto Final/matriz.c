#include <stdio.h> // rand é da stdlib
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_NUMBERS 143

//thats define poisitions for two numbers, the start and the destany
void generatePosition(int **matriz)
{
    srand(time(NULL));
    int YStart = rand() % 12;
    int XStart = rand() % 12;
    int YFinal = rand() % 12;
    int XFinal = rand() % 12;

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
}
