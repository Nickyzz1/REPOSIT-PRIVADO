#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Para sleep em sistemas Unix-like
// #include <windows.h> // Se estiver no Windows

int xEnemy = 0;
int yEnemy = 0;
int xCharc = 0;
int yCharc = 0;

int l = 9;
int c = 15;

int enemy = 8; // Modifiquei para 8 (inimigo) conforme mencionado
int prota = 10;

int sumR;
int sumL;
int sumT;
int sumD;

int aways[4] = {0, 0, 0, 0};
int lowest = 0;

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
    while (1) 
    {
        // Verifica se o inimigo alcançou o personagem
        if (matriz[xCharc][yCharc] == matriz[xEnemy][yEnemy]) 
        {
            printf("Você perdeu!\n");
            break;

        } else {
            int random = rand() % 2 + 2;
            // Reinicializa as variáveis de soma
            sumR = 0;
            sumL = 0;
            sumT = 0;
            sumD = 0;

            //left
            for(int col = 0; col < yEnemy ; col++)
            {
                sumL += matriz[xEnemy][col];  
            }
            aways[0] = sumL;

            //right
            for(int col = c - 1; col > yEnemy; col--)
            {
                sumR += matriz[xEnemy][col];  
            }
            aways[1] = sumR;

            //top todas as linhas acima e mesma coluna
            for(int line = 0; line < xEnemy; line++)
            {
                sumT += matriz[line][yEnemy];
            }
            aways[2] = sumT;

            //down todas as linhas abaixo e mesma coluna
            for(int line = l - 1; line > xEnemy; line--)
            {
                sumD += matriz[line][yEnemy];
            }
            aways[3] = sumD;

            // Verificar qual caminho tem a menor soma
            lowest = 0;

            for(int i = 0; i < 4; i++)
            {
                if (aways[i] < aways[lowest])
                {
                    lowest = i;
                }
            }

            // Atraso entre os movimentos
            sleep(1); // Espera 1 segundo entre cada movimento

            // Limpa a posição atual do inimigo na matriz
            matriz[xEnemy][yEnemy] = 0;

            if(random == 2)
            {
                // Aplica o movimento de acordo com o menor caminho encontrado
                if (lowest == 2 && xEnemy > 0) { // Movimento para cima
                    if (matriz[xEnemy - 1][yEnemy] == 0 || matriz[xEnemy - 1][yEnemy] == 10) {
                        xEnemy--;
                    }

                } else if (lowest == 3 && xEnemy < l - 1) { // Movimento para baixo
                    if (matriz[xEnemy + 1][yEnemy] == 0 || matriz[xEnemy + 1][yEnemy] == 10) {
                        xEnemy++;
                    }

                } else if (lowest == 0 && yEnemy > 0) { // Movimento para a esquerda
                    if (matriz[xEnemy][yEnemy - 1] == 0 || matriz[xEnemy][yEnemy - 1] == 10) {
                        yEnemy--;
                    }

                } else if (lowest == 1 && yEnemy < c - 1) { // Movimento para a direita
                    if (matriz[xEnemy][yEnemy + 1] == 0 || matriz[xEnemy][yEnemy + 1] == 10) {
                        yEnemy++;
                    }

                }

            } else {
                // Se todas as direções estiverem bloqueadas, tentar um movimento aleatório
                int randomMov;
                while (1) {
                    randomMov = rand() % 4;
                    if ((randomMov == 0 && xEnemy > 0 && (matriz[xEnemy - 1][yEnemy] == 0 || matriz[xEnemy - 1][yEnemy] == 10)) ||
                        (randomMov == 1 && xEnemy < l - 1 && (matriz[xEnemy + 1][yEnemy] == 0 || matriz[xEnemy + 1][yEnemy] == 10)) ||
                        (randomMov == 2 && yEnemy > 0 && (matriz[xEnemy][yEnemy - 1] == 0 || matriz[xEnemy][yEnemy - 1] == 10)) ||
                        (randomMov == 3 && yEnemy < c - 1 && (matriz[xEnemy][yEnemy + 1] == 0 || matriz[xEnemy][yEnemy + 1] == 10))) {
                        break;
                    }
                }

                    // Executar o movimento aleatório válido
                    if (randomMov == 0) {
                        xEnemy--;
                    } else if (randomMov == 1) {
                        xEnemy++;
                    } else if (randomMov == 2) {
                        yEnemy--;
                    } else if (randomMov == 3) {
                        yEnemy++;
                    }
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
