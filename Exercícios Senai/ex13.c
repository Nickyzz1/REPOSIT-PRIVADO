#include <stdio.h>

void remover(int * array, int len, int index){
    for(int i = index; i <len-1; i++){ //no index e vai até o fiunakl
        array[i] = array[i+1]; //sobrepõe
    }
    array[len-1] = 0;
    for(int i=0; i<len;i++){
        printf("%i", array[i]);
    }
}
int main(){
    int array[] = {1,2,3,4,5};
    int len = sizeof(array)/sizeof(array[0]);
    int index= 2;
    remover(array, len, index);
//     int result= remove(&array, len, index);
//     printf(result);
}