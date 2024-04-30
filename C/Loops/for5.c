#include <stdio.h>

int main(){
    int num;
    printf("Enter a number for recive multiples: ");
    scanf("%i", &num);
    for(int i = 1; i <=num;i++)
    {
        if(num%i==0)
        {
            printf("%i\n", i);
        }
    }
}
