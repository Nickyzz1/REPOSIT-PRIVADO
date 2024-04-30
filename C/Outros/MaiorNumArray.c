// Identifique o maior valor dentro de uma sequência de valores
// armazenadas em um array
#include <stdio.h>

int main(){
    int maior=0;
    int array[8] = {1, 0, 4 ,5 ,6, 101, 9, 8};
    for(int i=0; i<=7; i++)
    {
        if(maior < array[i])
        {
            maior = array[i];
        }
    }
    printf("\nThe biggest number: %i", maior);
}
