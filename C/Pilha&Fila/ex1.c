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

    printf("+--------------------------------+\n");
    printf("|          ENTER OPTION          |\n");
    printf("+================================+\n");
    printf("| OPCAO  | OPERACAO              |\n");
    printf("+================================+\n");
    printf("| 1 -    | PUSH                  |\n");
    printf("| 2 -    | POP                   |\n");
    printf("| 3 -    | TOP                   |\n");
    printf("| 4 -    | ENQUEUE               |\n");
    printf("| 5 -    | DEQUEUE               |\n");
    printf("| 0 -    | SAIR                  |\n");
    printf("+--------------------------------+\n");
    

    scanf("%d", &option);

    int flag =1;

    while(flag == 1 )
    {
        switch (option)
        {    
            
        case 1: //add um elemnto no início da pilha

            printf("Enter a number to push: ");

            scanf("%i", &num);

            int * result = push(array, len, num);

            printf("Result of push:");
            for (int i = 0; i < len; i++) 
            {
                printf("\n[%i]", result[i]);
            }

            free(result);
            break;

        case 2: //remove o elemento do topo da pilha

            result = pop(array, len);

            printf("Result of pop: ");
            for (int i = 0; i < len - 1; i++) 
            {
                printf("\n[%i]", result[i]);
            }

            free(result);
            break;

        case 3: //retorna o elemnto do topo da pilha sem removê-lo
            
                result = top(array, len);
                printf("Result of top: %i", result);

                free(result);
                break;
            
        case 4:  //add um lemento ao incio da fila
        
            printf("Enter a number to enqueue: ");

            scanf("%i", &num);

            result = enqueue(array, len, num);

            printf("Result of enqueue: ");
            for (int i = 0; i < len; i++) 
            {
                printf("%i ", result[i]);

            }

            free(result);
            break;

        case 5: //remove um elemento do inicio da fila

            result = pop(array, len);

            printf("Result of dequeue: ");

            for (int i = 0; i < len - 1; i++) 
            {
                printf("%i ", result[i]);
            }

            free(result);
            break;   
            

        case 0:

            printf("okay!!");
            break;
    
        }
    }
}
