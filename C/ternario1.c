#include <stdio.h>

int main() {
    float n;
    int e;

    printf("Escolha de acordo com o número:\n 1- converter Farenheit para Celsius;\n 2- Converter Celsius para Fahrenheit\n");
    scanf("%d", &e);

    e == 1 ?
        (
            printf("Escolha um número em Fahrenheit para converter para Celsius: "),
            scanf("%f", &n),
            printf("Celsius: %f\n", (n - 32) / 1.8)
        ) :
        (
            e == 2 ?
            (
                printf("Escolha um número em Celsius para converter para Fahrenheit: "),
                scanf("%f", &n),
                printf("O valor em Fahrenheit: %f\n", n * 1.8 + 32);
            ) :
            printf("DIGITE UMA OPÇÃO VÁLIDA!\n")
        );

    return 0;
}
