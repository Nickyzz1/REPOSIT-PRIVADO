#include <stdio.h>
#include <string.h>

char word[5] = "termo";
char vazio[5] ="_____";

void start(){
    printf("\n/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");

}

int verificar(char guess){
    int fla =1;
    for(int i=0; i<5;i++)
    {
        if(guess==word[i])
        {
            vazio[i] = word[i];
            fla = 0;
        }
    }
    if(fla==0)
    {
        return 0;
    }
    return 1;  
}

int main(){
    start();
    char guess;
    int life =6;
    while(life>=0)
    {
        printf("\n%s", vazio);
        printf("\nEnter a letter:\n");
        scanf(" %c", &guess);
        life -=verificar(guess);
        printf("\nYour life is: %i\n", life);
        if(strcmp(vazio,word)==0)
        {
                printf("\n%s\n", word);
                printf("\nYou win!"); 
            break;
        }
    } 
}
