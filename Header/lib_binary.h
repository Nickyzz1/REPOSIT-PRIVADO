#include <stdio.h>
#ifndef FUNCTION_C.H
#define FUNCTION_C.H
//and,not, nand, or, nor, xor, nxor

int Not(int a){
    return ~a;
}

int And(int a, int b){
    return a & b; 
}

int Nand(int a, int b){
    return ~(a && b);
}

int Or(int a, int b){
    return a | b;
}

int Nor(int a, int b){
    return ~(a | b);
}

int Xor(int a, int b){
    return a ^ b ;
}
int Nxor(int a, int b){
    return ~(a ^ b);

}
    
#endif // !FUNTION_C.h
