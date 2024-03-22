// 1 - Faça um jogo da forca em linguagem C onde o usuário consiga adivinhar a palavra com o número máximo de tentavas sendo 6. O programa deve ser feito todo baseado em funções.

#include <stdio.h>
#include <string.h>
 
void adivinhar()
{
    int tent = 6;
    char word[5] = "termo";
    char userword[255];
    int i;
    int strtamanho= strlen(word);

    printf("This is the hangman game! Enter an letter to play! ");
    scanf("%s", &userword);
    while(tent>=0)
    {
        if(strcmp(userword, word))

    }


int main(){
    adivinhar();

}
}


#include <string.h>
#include <stdio.h>

int main() {

  char str[20];
  gets(str);
  int i;
  int strLength = strlen(str);

  for (i = 0; i < strLength; i++) {

      if (strcmp(str[i],"c") == 0)
      {
        printf("Achei");
      }

      printf("[%c]", str[i]);

  }
}
