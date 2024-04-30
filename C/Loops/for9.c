#include <stdio.h> 

int main(){
    int num;
    int count =0;
    int total =0;
    int media=0;
    printf("Enter how many numbers you wnat to calculator: ");
    scanf("%i", &count);
    for(int i=1; i<=count; i++)
    {
        printf("Enter one of the numbers:");
        scanf("%i",&num);
        total+=num;
    }
    media = total/count;
    printf("The mean is: %i", media);
    
}
