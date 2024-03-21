#include <stdio.h>

int main(){
    int num;

    printf("ENTER A NUMBER FOR DISCOVER PRIME NUMBERS: ");
    scanf("%i", &num);
    for(int i = 1; i <num+1; i++)
    {
       for(int j = 1; j<num+1; j++)
       {
            if(i%j!=0)
            {
                

            }
       }
        printf("%i",i);
    }

}
