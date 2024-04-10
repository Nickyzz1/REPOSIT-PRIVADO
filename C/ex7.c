#include <stdio.h>

int main(){
    char array[][6] = {"Alice", "Bob", "Carol", "David"};
    int len = sizeof(array)/sizeof(array[0]);
    for(int i=0; i<len; i++){
        printf("%s, ", array[i]);
    }}
