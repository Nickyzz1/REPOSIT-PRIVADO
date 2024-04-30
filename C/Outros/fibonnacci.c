#include <stdio.h>

int fib(int *array, int len, int limite){
    for(int i=1; i<limite;i++){
        int temp = array[i];
        int resultado = temp + array[i-1];
        array[len]= resultado;
        len+=1;
    }
    for(int i =0; i<len;i++){
        printf("%i ,", array[i]);
    }
}
int main(){
    int array[]={1,1};
    int len = sizeof(array)/sizeof(array[0]);    
    int limite;
    printf("Enter a limite for fibonnacci serie: ");
    scanf("%i", &limite);
    fib(&array, len, limite);
}
