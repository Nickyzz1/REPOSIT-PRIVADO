#include <stdio.h>

int tabuadaRecursiva(int num, int multiplicador){

    if(multiplicador == 0){
        return 1;
    }
    else{
        printf("The product of %d x %d is: %d\n",num,multiplicador, num * multiplicador);
        return tabuadaRecursiva(num, multiplicador - 1);
    }
}

int main(){
    tabuadaRecursiva(10,10);
}
