#include <stdio.h>
#include <unistd.h>

int main(){
    int prod= 0;
    printf("Enter how many products you want buy: ");
    scanf("%i", &prod);
    printf("Loadind...");

    for(int i =0; i<prod; i++){
        printf("*");
        sleep(1);
    };
    printf("SUCESSFULLY!");
}
