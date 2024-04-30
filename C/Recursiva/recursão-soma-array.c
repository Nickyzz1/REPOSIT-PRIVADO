#include <stdio.h>

int sum(int * array, int len){
    if(len == 0){
        return 1;
    }
    else{
        return array[len] + sum(array, len -1);
    }
}

int main(){
    int array[] = {1,2,3,20};
    int len = sizeof(array)/sizeof(array[0]);
    int result;
    result = sum(&array, len);
    printf("%i", result);
}
