#include <stdio.h>
#include <stdlib.h>
#ifndef HEADER_H
#define HEADER_H

//push
int * push(int * array, int len, int num)
{
    int * newArray = (int *) malloc(sizeof(int)*(len+1));
    newArray[0] = num;

    for(int i = 1; i < len; i++)
    {
        newArray[i] = array[i];
    }
    for(int i = 0; i < len + 1; i++)
    {
        printf("%i", *newArray[i]);
    }

    return newArray;
}

//pop

//top



//fila
//enqueue

//dequeue



#endif
