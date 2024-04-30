#include <stdio.h>

int main() {
    int n1;
    int n2;
    printf("Escolha um número: ");
    scanf("%i", &n1);
    printf("Escolha outro número: ");
    scanf("%i", &n2);
   
    // Operador NOT (~)
    int not_n1 = ~n1; 
    //se o 

    // Operador AND (&)
    int and_result = n1 & n2; // Resultado: 00000000 00000000 00000000 00000000

    // Operador XOR (^)
    int xor_result = n1 ^ n2; // Resultado: 00000000 00000000 00000000 00001111

    // Operador OR (|)
    int or_result = n1 | n2; // Resultado: 00000000 00000000 00000000 00001111

    // Operador Shift Left (<<)
    int shift_left_result = n1 << 1; // Resultado: 00000000 00000000 00000000 00010100

    // Operador Shift Right (>>)
    int shift_right_result = n1 >> 1; // Resultado: 00000000 00000000 00000000 00000101

    // Exibindo resultados
    printf("NOT (~a): %i\n", not_n1);
    printf("AND (a & b): %i\n", and_result);
    printf("XOR (a ^ b): %i\n", xor_result);
    printf("OR (a | b): %i\n", or_result);
    printf("Shift Left (a << 1): %i\n", shift_left_result);
    printf("Shift Right (a >> 1): %i\n", shift_right_result);

    return 0;
}
