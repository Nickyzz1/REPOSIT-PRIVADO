#include <stdio.h>

int main(){
    int fla =1;
   
    while(fla == 1){

        int value = 45;
        int num1=0;
        int num2=0;
        int num3=0;
        int soma=0;
        
        printf("Try sum 45!");
        printf("Enter first number\n: ");
        scanf("%i", &num1);
        printf("\nEnter second number\n: ");
        scanf("%i", &num2);
        printf("\nEnter third number\n: ");
        scanf("%i", &num3);
        soma = num1+num2+num3;
        if(soma!=value){
            printf("Try again!\n");
        }
        else{
            printf("Sucessfully!");
            fla =0;
        }}

}
