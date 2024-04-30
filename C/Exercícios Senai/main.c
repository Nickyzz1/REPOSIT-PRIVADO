// TESLA USA LINGUAGEM C
// LINGUAGEM DE NÍVEL MÉDIO
// MAIN contém o código principal que será executado

#include <stdio.h>  //chama uma biblioteca, biblioteca padrão chama o C, padrão entrada e saída
// void = vazio
//main
//o que é int, void, char
//; --> separa uma instrução de outra // td c
//double e float permitem número com casdas decimais, double permite +casas
int main(){
    int numero = 2; //sempre é necessário declarar o tipo de variável
    printf("%i\n",numero);  //saída de dados" %i" = define que a str "%i" terá o valor da variável número
    signed num = -2;
    printf("%i", num);
    printf("Digite um número: ");
    signed n = 0 ;
    scanf("%i",&n);
    printf("%i", n);
    
    return 0; //retorna para o início, é a porta se sáida da função
}
