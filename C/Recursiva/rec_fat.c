#include <stdio.h>

int fatorial(int num){
    if(num==0){
        return 1;
    }
    else{
        return num * fatorial(num-1);
    }
}
int main(){
    int num;
    int result;
    printf("Enter a number for figuring out his fatorial: ");
    scanf("%i", &num);
    result = fatorial(num);
    printf("The fatorial: %i", result);
}
