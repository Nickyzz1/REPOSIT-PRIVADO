#include <stdio.h>

int main(){
    int num;
    int f;
    printf("ENTER HOW MANY ASTERISKS DO YOU WANT TO PRINT:");
    scanf("%i", &num);
    printf("ENTER WHICH SHAPE DO YOU WANT?\n 1-TRIANGLE OR 2-SQUARE: ");
    scanf("%i", &f);
    if(f==1)
    {
        for(int i =1;i<=num; i++)
        {
            for(int j =1; j<=i;j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else if(f==2)
    {
        for(int i =1;i<=num; i++)
        {
            for(int j =1; j<=num;j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }

}
