#include <stdio.h>

int main(){
    int num=100, count =0, i =0;
    for(int j = 1; j <num+1; j++) 
    {
        count =0;
        for(int i = 1; i<num+1; i++)
        {
                if(j % i ==0)
                {
                count++;
                }
            }
            if(count==2)
            {
                printf("%i\n", j);
            }
    }  
}
