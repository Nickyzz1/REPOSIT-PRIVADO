# include "header.h"

int main(){
    int lines;
    int col;
    printf("Enter lines: ");
    scanf("%i", &lines );
    printf("Enter columns: ");
    scanf("%i", &col );
    int **matriz = allocmemory(lines, col);
    for(int i=0;i<lines;i++){
        for(int j=0;j<col;j++){
            printf("ENTER A NUMBER FOR MATRIZ: ");
            scanf("%i", &matriz[i][j]);
        }
    }
    for(int i=0;i<lines;i++){
        for(int j=0;j<col;j++){
            printf("[%i],", matriz[i][j]);
        } 
        printf("\n");
    }
}
