#include <stdio.h>

void invert(int * array, int len){
    for(int i =0; i<(len)/2; i++){
        int temp = array[i]; //-1 poois o tamanho vai até 6 e o indice vai só até o 5(0,1,2,3,4,5), - ipara pegar os dois números quie devem trocar, por exemplo 1 e 6, 2 e 5, 3 e 4;
        array[i] = array[len-i-1];
        array[len-i-1]= temp;
    }
    for(int i=0; i<len; i++){
        printf("%i", array[i]);
    }
}
int main(){
    int array[] = {1,2,3,4,5,6};
    int len = sizeof(array)/sizeof(array[0]);
    invert(&array, len);
}
