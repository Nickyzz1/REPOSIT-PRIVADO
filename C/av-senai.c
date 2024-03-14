#include <stdio.h>

int main() {
    int n1;
    int n2;
    int e;
    int fla =1;
    while (fla =1){
        printf("Chose one number: ");
        scanf("%i", &n1);
        printf("Chose another number: ");
        scanf("%i", &n2);
        printf("Enter the option that you want for the number:\n\n1-NOT\n2-AND\n3-OR\n4-XOR\n");
        scanf("%i", &e );
        if (e==1){
            int not_n1 = ~n1; 
            printf("NOT: %i\n", not_n1);
        }
        else if(e==2){
            int and_result = n1 & n2;
            printf("AND: %i\n", and_result);
        }
        else if (e==3){
            int or_result = n1 | n2;
            printf("OR: %i\n", or_result);
        }
        else if(e==4){

            int xor_result = n1 ^ n2;
            printf("XOR: %i\n", xor_result);
        }
        else{
            printf("Enter valid number!");
            break;
        }
   

    }
    
    return 0;
}
