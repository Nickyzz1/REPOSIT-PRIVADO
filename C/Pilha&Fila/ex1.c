#include <stdio.h>
#include "header.h"
// Desenvolva os métodos de cada um dos dos tipos de estruturas de
// dados(pilha e fila) e aplique em um programa da linguagem C. Utilize uma
// header para a criação das funções.
int main()
{
    int option;
    int num;
    int array[] = {2,3,4,5,6,7,8,9,0};
    int len = sizeof(array)/sizeof(array[0]);

    printf("==================================\n");
    printf("===========ENTER OPTION===========\n");
    printf("1 - PUSH =========================\n");
    printf("2 - POP ==========================\n");
    printf("3 - TOP ==========================\n");
    printf("4 - ENQUEUE ======================\n");
    printf("5 - DEQUEUE ======================\n");

    scanf("%d", &option);

    switch (option)
    {
    case 1:

        printf("Enter a number to push: ");
        scanf("%i", &num);
        push(array, len, num);
        for(int i = 0; i < len; i++){

            
        }
    
        break;
    
    default:
        break;
    }

    


}
