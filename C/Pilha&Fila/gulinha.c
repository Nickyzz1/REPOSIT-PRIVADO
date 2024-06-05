#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    
    int peopleOnQueue = rand() % 60;
    int people = peopleOnQueue;
    int giveUp;
    int *gulinha = (int*)malloc(sizeof(int) * peopleOnQueue);

    while (1) 
    {
        printf("you are in that position: %d", people);
        printf("\nThe quantity of people on the queue is: %d\n", peopleOnQueue);
        if(people == 0)
        {
            printf("You are served");
        }
        else
        {
            if (peopleOnQueue < 60) 
            {
                peopleOnQueue++;
                gulinha = (int*)realloc(gulinha, sizeof(int) * peopleOnQueue);
                printf("There's still room to get in line\n");
                giveUp = rand() % 100;
    
                if (giveUp > 80)
                {
                    int peopleLeaving = rand() % peopleOnQueue;
                    if(peopleLeaving == people)
                    {
                        printf("You leaving the line");
                        break;
                    }
                    else
                    {
                        printf("\nThe line is too long, someone is leaving: %d\n", peopleLeaving);
                        peopleOnQueue--;
                        
                        if(peopleLeaving < people)
                        {
                           people--;
                           printf("Now your position is %d", people);
                        }
                    }
                    people--;
                }
            }
            else if(peopleOnQueue >= 60){
                printf("The queues is full, the line is closed\n");
                printf("you are served");
            }
        }
    }
}


// Exibir a quantidade de pessoas dentro da fila(Elementos)
// Permitir a entrada de novas pessoas dentro da fila(De maneira que há chance de entrar na fila ou não)
// Ao acabar a fila, encerrar o programa.
// Há uma chance de uma pessoa desistir da fila, assim saindo dela.
// Exibir mensagens como "Compra finalizada", "Fim da fila, programa encerrando"
// Das 8:00 até as 17:00 o movimento é menor. Das 17:00 as 22:00 o movimento cresce de maneira considerável.
