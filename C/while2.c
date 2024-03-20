#include <stdio.h>

int main(){
    int max = 60;
    int value=0;
    while(value < max){
        printf("Enter the amount you want to kit:  ");
        scanf("%i", &value);
        if (value < max){
            printf("You cannot withdraw this amount!\n\n");
        }
        else{

            printf("The value %i was whithdraw succesfully!\n", value);
        }
    }
    return 0;
}
