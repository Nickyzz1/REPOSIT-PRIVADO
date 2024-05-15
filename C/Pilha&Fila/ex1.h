#include <stdio.h>
#include <stdlib.h>
#ifndef HEADER_H
#define HEADER_H

//add um elemento ao topod na pilha
int * push(int * array, int len, int num)
{
    int * newArray = (int *) malloc(sizeof(int)*(len+1));
    newArray[0] = num;

    for(int i = 0; i < len; i++)
    {
        newArray[i+1] = array[i];
    }
    
    return newArray;
}

//remove o elemnto do topod a pilha

int * pop( int * array, int len)
{
    for(int i = 0; i < len; i++)
    {
        array[i] = array[i+1];
    }
    return array;
}

//retorna o elemnto do topo da pilha

int * top(int * array, int len)
{

    return array[0];
}

//add um elemento ao início da fila
int * enqueue(int * array, int len, int num)
{
    int * newArray = (int *) malloc(sizeof(int)*(len+1));
    newArray[0] = num;

    for(int i = 0; i < len; i++)
    {
        newArray[i+1] = array[i];
    }
    
    return newArray;


}

//remove um elemento do inicio da fila
int dequeue(int * array, int len)
{
    for(int i = 0; i < len; i++)
    {
        array[i] = array[i+1];
    }
    return array;
}



#endif
