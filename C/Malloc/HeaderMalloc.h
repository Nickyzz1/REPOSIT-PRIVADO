#include <stdio.h>
#include <stdlib.h>
#ifndef HEADER_H
#define HEADER_H

int **allocmemory(int lines, int col){
    int ** matriz = malloc(sizeof(int*)*lines);
    for(int i =0;i<lines;i++ ){
        matriz[i] = malloc(sizeof(int)*col);
    }
    return matriz;
}

#endif
