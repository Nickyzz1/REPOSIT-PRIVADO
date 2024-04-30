#include <stdio.h>
// Crie um programa que simule uma questão de relacionar colunas de uma prova. Defina a posição das respostas e das afirmações e permita o usuário relacionar
// elas e ver se sua resposta está correta ao final do programa.
int main(){
    int answerA;
    int answerB;
    int answerC;
    int fla =1;
    while(fla==1){
        printf("\nRelate the options with the band:\n\n");
        char matriz_music[3][14]=
        {
            {"A-Nero forte"}, //\0 é um indicador do final da string
            {"B-Kriptonite"},
            {"C-Numb"}
        };
        for(int i=0; i<3;i++){
            printf("%s\n", matriz_music[i]);
        }
        printf("%s","___________________OPTIONS______________________\n\n");
        char matriz_answer[3][15]={
            {"1-3 Doors Down"},
            {"2-Linkin Park"},
            {"3-Slipknot\n"}
        };
        for(int j =0; j <3; j++){
            printf("%s\n", matriz_answer[j]);
        }
        printf("Enter your answer of the option A: ");
        scanf("%i",&answerA);
        printf("\nEnter your answer of the option B: ");
        scanf("%i",&answerB);
        printf("\nEnter your answer of the option C: ");
        scanf("%i",&answerC);
        if(answerA==3 && answerB==1 && answerC==2){
            printf("You are right!\n");
            fla=0;
        }else{
            printf("\nSomethig was wrong! Try again!\n");
        }

    } 
}
