#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Gulinha{
    int quant;
};

int main(){

    srand(time(NULL));
    int giveUp;
    
    struct Gulinha queue;
    
    do 
        {
            giveUp = rand() % 100;
            printf("%i", giveUp);
            printf("%s", "\n");
        }
    while(giveUp < 50);
}
