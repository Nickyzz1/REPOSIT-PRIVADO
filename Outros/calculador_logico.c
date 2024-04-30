#include "Binary.h"

int main(){
    int a;
    int b;
    int op;

    printf("\nYou're using an binary calculator! For each number you write here, it's binary wiil be analyzed!\n So, enter one number: ");
    scanf("%i", &a);
    printf("\nEnter another number: \n");
    scanf("%i", &b);
    printf("Now choose the operation:\n0-NOT\n1-AND\n2-NAND\n3-OR\n4-NOR\n5-XOR\n6-NXOR\n");
    scanf("%i", &op);

    if(op==0){        printf("\n%i", Not(a));
        printf("\n%i", Not(b));
    }
    else if(op ==1){
        printf("\n%i", And(a,b));
    }
    else if(op == 2){
        printf("\n%i", Nand(a,b));
    }
    else if(op==3){
        printf("\n%i", Or(a,b));
    }
    else if(op==4){
        printf("\n%i", Nor(a,b));
    }
    else if(op==5){
        printf("\n%i", Xor(a,b));
    }
    else if(op==6){
        printf("\n%i", Xor(a,b));
    }
}
