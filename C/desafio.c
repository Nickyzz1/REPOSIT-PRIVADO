#include <stdio.h>

int main(){
    int e;
    printf("CHOSE OPTIONS:\n\n 1- PANIFICADORA\n 2-LIMPEZA\n 3-ALIMENTAÇÃO\n 5-BEBIDAS");
    if (e==1){
        int pan;
        float pao = 1.40;
        float salgado = 3.50;
        float paoq = 1.2;
        float assado = 4;
        printf("Okay, set one products you want:\n\n 1-PÃO: $1,40\n 2-SALGADO: $3,50\n 3-PÃO DE QUEIJO: $1,20\n 4-ASSADO: $ 4,00");
        scanf("%i", &pan);
        printf("deseja escolher mnais algum produto? 1-sim, 0-não: ");

              
    }
    
    return 0;
}
