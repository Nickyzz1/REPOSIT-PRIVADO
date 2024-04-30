#include <stdio.h>
// Escreva um programa que declare um inteiro, um real e um char, e
// ponteiros para inteiro, real e char. Associe as variáveis aos ponteiros (use
// &). Modifique os valores de cada variável usando os ponteiros. Imprima os
// valores das variáveis antes e após a modificação.
void receber(char *name, int *num1, float *real ){

    char new_name[] = "n";
    *name = &new_name;
    *num1 = 1;
    *real = 0.8;

}

int main(){
    char name[] = "w";
    int num1 = 10;
    float real = 0.5;
    printf("-----------------\nTHE OLD VALUES:\n\n%s\n%i\n%f\n", name, num1, real);
    receber(&name, &num1,&real);
   
    printf("-----------------\nTHE NEWS VALUES:\n\n%s\n%i\n%f\n", name, num1, real);
}   
