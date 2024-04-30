#include <stdio.h>
//somar vetor recbe vetor como nparametro e retorna a soma de tds os elememntp do vetror

int somarvetor(int * array, int len){
    int soma = 0;
    for(int i = 0; i<len; i++){
        soma += array[i];
    }
    return soma;
}

int main(){
    int array[]= {1,2,3,10};
    int len = sizeof(array)/sizeof(array[0]);
    int resultado = somarvetor(&array, len);
    printf("%i", resultado);
}