#include <stdio.h>

int fib(int *array, int len, int limit){
    if(len == limit){
        return 1;
    }
    else{
        int num = array[len]+ array[len-1];
        array[len] = num;
        len +=1;
        printf("%i", array[len]);
        return fib(&array, len+1, limit);
    }
}

int main(){
    int array[] ={1,1};
    int len = sizeof(array)/sizeof(array[0]);
    int limit;
    printf("Enter a limit for fibonnacci serie: ");
    scanf("%i", &limit);
    int * result = fib(&array, len, limit);
    for(int i=0; i<limit;i++){
        printf("%i", result[i]);

    }
}
