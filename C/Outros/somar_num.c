#include <stdio.h.>

int calcular(int num){ //o que vai diminuir na minha função?
    static int resultado = 0;
    if(num==0){
        printf("%i", resultado);
        return 0;
    }
    else{
        resultado += num; //o resultado está guaradando o valor 2
        num--; //num-1
        calcular(num); //o nv valor da função é num-1, no caso, 1
    }
    return 1;
}
//onde irei chamar todas as funções
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%i",&num);
    calcular(num);
}
