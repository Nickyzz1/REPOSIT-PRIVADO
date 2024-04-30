#include <stdio.h>

//maiorleemento revce array de parametro de inteiros e seu tamaanho retorna o maior num da array
int maior(int * array, int len){
    int result =0;
    for(int i=0; i<len; i++){
        if(result < array[i]){
            result = array[i];
        }
    }
    return result;
}

int main(){
    int array[] = {1,3,0,1200,1};
    int len = sizeof(array)/sizeof(array[0]);
    int result = maior(&array, len);
    printf("The biggest number: %i", result);
}