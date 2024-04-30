#include<stdio.h>
// Escreva um programa que calcula o fatorial de um número inteiro não negativo fornecido pelo usuário.
int fatorial(int num){
    int anterior = num -1;
    if(num==0 || num ==1){
        return 1;
    }
    else{
        return num * fatorial(anterior);   
               //12
    }  
}
int main(){
    int num =0;
    printf("Enter a number for discover his fatorial: \n");
    scanf("%i", &num);
    int result = fatorial(num);
    printf("%i", result);

}
