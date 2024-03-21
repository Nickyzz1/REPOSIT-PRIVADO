#include <stdio.h>
#include <string.h> // Para strcmp()

int main(){
    char password[] = "qwertyuiop"; // Senha correta
    char userpassword[256]; // Array para armazenar a senha digitada pelo usuário
    
    printf("Enter your password: ");
    scanf("%255s", userpassword); // o 255 siginifica que é o número máximo de caracteres que o scanf lerá Lê a senha como uma string

    while(strcmp(password, userpassword) != 0){ // Compara as strings
    //strcmp se as strings forem iguais o número retornado é zero
        printf("That value is not permitted! Try again:\n");
        scanf("%255s", userpassword); // Lê a senha novamente se a anterior for incorreta
    }

    printf("Login successfully!\n");

    return 0;
}  
