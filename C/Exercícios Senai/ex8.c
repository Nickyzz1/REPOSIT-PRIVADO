#include <stdio.h>

int indice(int * array, int num, int len){
    for(int i=0; i<len; i++){
        if(array[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
    int array[] = {2,1,3,45,6,7,8,100};
    int len = sizeof(array)/sizeof(array[0]);
    int num;
    printf("Enter a number for figuring out if it is on vetor: ");
    scanf("%i", &num);
    int result = indice(&array, num, len);
    printf("%i", result);
}