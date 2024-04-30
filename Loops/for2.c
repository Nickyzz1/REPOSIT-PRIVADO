#include <stdio.h>

int main(){
    int num;
    int soma = 0;
    printf("Enter one number for sum all natural numbers: ");
    scanf("%i", &num);

    for(int i =0; i<num+1; i++){
        soma +=i;
    }
    printf("%i", soma);

    return 0;
}
