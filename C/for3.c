#include <stdio.h>

int main(){
    int num;
    int mul;

    printf("Enter a number for get your multiplication tables: ");
    scanf("%i", &num);
    for(int i = 0; i<11; i++)
    {
        mul = num*i;
        printf("%i\n",mul);

    }

    
    return 0;
}
