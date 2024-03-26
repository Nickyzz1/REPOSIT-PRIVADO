#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char word[5]="termo";
char chute[5] = "*****";


void start(){
    printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");

}

void chutes() {
	char letter;
	printf("Enter a letter?\n");
	scanf("%c", &letter);

	if(conf(letter)) {
		printf("GREAT! You're right, no long to go! %c\n\n", letter);
        for(unsigned int i=0;i<strlen(word); i++ )
        {
            
        }
	} else {
		printf("\nFAIL! Try again, but remenber, yourchances are runninf out! %c\n\n", letter);
	}
}

int conf(char letter){

    for(unsigned int i =0; i < strlen(word); i++)
    {
        if(letter == word[i])
        {
           return 1;
        }
    }
    return 0;
}

// int pont(){
//     continue;
// }



int main(){
    start();
    chutes();

}
