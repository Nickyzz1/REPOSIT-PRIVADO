#include <stdio.h>

char matriz[5][5] = 
    {
        {'1', -77, '2', -77,'3'},
        {-60, -59, -60, -59,-60},
        {'4', -77, '5', -77,'6'},
        {-60, -59, -60, -59,-60},
        {'7', -77, '8', -77,'9'}
    };

// void sub_x(){
//     char index;
//     printf("Player 1(x): Enter a number for play: \n");
//     scanf("%c", &index);
//     for(int i =0; i<5;i++){
//         for(int j =0; j<5;j++){
//             if(matriz[j][i] == index){
//                 matriz[j][i] = 'X';
//             }
//         }
//     }
//     sub_o();
    
// }

int main(){

    char index;
    int fla =1;
    while(fla == 1){
        for(int i =0; i<5;i++){
            for(int j =0; j<5;j++){
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }
    printf("Player 1(x): Enter a number for play: \n");
    scanf("%c", &index);
    for(int i =0; i<5;i++){
        for(int j =0; j<5;j++){
            if(matriz[j][i] == index){
                matriz[j][i] = 'X';
            }
        }
    }
    }
    printf("Player 2(o): Enter a number for play: \n");
    scanf("%c", &index);
    for(int i =0; i<5;i++){
        for(int j =0; j<5;j++){
            if(matriz[j][i] == index){
                matriz[j][i] = 'O';
            }
        }
    }
}
