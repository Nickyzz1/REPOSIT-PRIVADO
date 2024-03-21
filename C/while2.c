#include <stdio.h>

int main(){
    int max = 60;
    int choose = 0;
    int value=0;
    int fla =1;
    while(fla==1 ){
        int saldo;
        printf("Enter the number about what do you want access:\n1-Withdraw\n2-Deposit\n");
        scanf("%i", &choose);
        if(choose ==2){
            printf("Enter the amount you want to Deposit:  ");
            scanf("%i", &value);
            saldo = saldo + value;
        }
        if(choose==1){
            printf("Enter de value thats you want kit: ");
            scanf("%i", &value);
            if (value < max || value >saldo ){
                printf("You cannot withdraw this amount!\n\n");
            }
            if(value>=max && value<=saldo){

                printf("The value %i was whithdraw succesfully!\n", value);
            }}}
        return 0; 
    }
    
