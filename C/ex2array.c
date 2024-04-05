#include <stdio.h>

int main(){
    int array[3]= {1,2,3};
    int num =0;
    for(int i =0; i<3; i++)
    {
        num += array[i];
    }
    printf("%i", num);
}
