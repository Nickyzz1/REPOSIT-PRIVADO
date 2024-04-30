#include <stdio.h>
#ifndef FUNC_H
#define FUNC_H
//- Faça um programa para um banco que permita fazer as operações bancárias, como depósito, saque, extrato, empréstimo usar txt para imprimir as funções necessárias. Desenvolva as funções dentro de uma header

float Saque(float saque, float total){
    return total - saque;
}

float Deposit(float valor, float total){
    return total+valor;
}

float Emp(float valor){
    return valor;
}


#endif 
