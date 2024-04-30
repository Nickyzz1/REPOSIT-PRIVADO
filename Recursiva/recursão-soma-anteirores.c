#include <stdio.h>

int sum(int num){
    if(num==0){
        return 1;
    }
    else{
        return num += sum(num-1);
    }
}
int main(){
    int num;
    int resultado;
    printf("Enter a number for figuring out your sum:");
    scanf("%i", &num);
    resultado = sum(num);
    printf("%i", resultado-1);
}
