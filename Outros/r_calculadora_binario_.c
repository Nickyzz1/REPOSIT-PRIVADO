#include <stdio.h>

int calculadora(int num){
    if(num==1){
        printf("%i", 1);
        return 0;
    }
    calculadora(num/2);
    printf("%i", num%2);
    return 0;
    
}
int main(){
    int num =0;
    printf("Enter a number for binary: ");
    scanf("%i", &num);
    calculadora(num);
}
