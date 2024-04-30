#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int num;
    int limsup = 100;
    srand(time(NULL));
    num = rand() % (limsup+1);
    printf("Random Nuber: %d\n", num);

    return 0;
}
