#include <stdio.h>

int main(){

    int palpite;
    int resposta = 100;
    while(palpite != resposta){
        printf("THE COMPUTHER CHOSE A NUMBER FROM 1 TO 1000! ENTER YOUR HINT: ");
        scanf("%i", &palpite);
        if (palpite!=resposta){
            printf("No, you're wrong, try again:\n");
        }
        else{
            printf("You're right, the number was: %i", resposta);
        }
} }
