#include <stdio.h>

int main(){
    int num, count =0, i =0;

    printf("ENTER A NUMBER FOR DISCOVER PRIME NUMBERS: ");
    scanf("%i", &num);
    for(int j = 1; j <num+1; j++) //começa em 1e  vai até op num,de 1 em 1
    {
        count =0; //defini o count como zero poisn ele contará quantas vezes a divisãod e cada número deus zero
        for(int i = 1; i<num+1; i++)
        {
                if(j % i ==0)
                {
                count++;
                }
            }
            if(count==2) //se forem duas, 1 e ele mesmo, significa ser primo
            {
                printf("%i\n", j);
            }
        }  
}
