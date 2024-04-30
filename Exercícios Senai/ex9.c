#include <stdio.h>

void imparpar(int * array, int len){
    int par=0;
    int impar=0;
    for(int i = 0; i<len; i++){
        if(array[i]%2==0){
            par+=1;
        }else{
            impar+=1;
        }
    }
    printf("EVEN: %i\n", par);
    printf("ODS: %i", impar);
}

int main(){
    int array[] = {1,2,3,4,5,67,0,100,1};
    int len = sizeof(array)/sizeof(array[0]);
    imparpar(&array, len);
    // printf("%i", result);
}