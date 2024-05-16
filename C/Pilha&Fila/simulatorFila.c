#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <Windows.h>

//probabilidade de sair
int probabilytyOut()
{
    Sleep(1);
    int chanceOut = rand() % 100;
    return chanceOut;
}

//probabilidade de entrar
int probabilytyIn()
{
    Sleep(1);
    int chanceIn = rand() % 100;
    return chanceIn;
}

int givenUp()
{
    Sleep(1);
    int givenUp = rand() % 100;
    return givenUp;
}

//add pessoa
void addPerson(char **queue, int  quantPeople)
{
    //criando items da fila
    char *people[] = {"Akik", "Sabrina", "Andrey", "Trevisan", "Nicolas", "Karlla", "Eduardo", "JoaoEmo", "Kau"};
    int lenPeople = sizeof(people) / sizeof(people[0]);

    //adcionando
    for(int i = 0; i < quantPeople; i++)
    {
        int indexPeople = rand() % lenPeople;
        // Aloca memória para a string
        queue[i] = malloc(strlen(people[indexPeople]) + 1);
        // Copia a string para a fila
        strcpy(queue[i], people[indexPeople]); 
    }
}

//imprimir itens
void show(char **queue, int quantPeople)
{
    for(int i = 0; i < quantPeople; i++)
    {
        printf("[%s]\n", queue[i]); 
    }
}

int main()
{
    srand(time(NULL)); // Inicialização da semente para geração de números aleatórios

    //criando a fila
    int limit = 8; // Ajustado para permitir quantidades entre 1 e 5
    char **queue = (char **)malloc(sizeof(char *) * limit);
    addPerson(queue, limit);

    int flag = 1;

    while(flag == 1)
    {
        int menuOption;
        //menu
        printf("\n+------------------------------+\n");
        printf("|          ENTER OPTION          |\n");
        printf("+================================+\n");
        printf("| OPTION  | OPERATIOJN           |\n");
        printf("+================================+\n");
        printf("| 1 -    | SEE QUEUE             |\n");
        printf("| 2 -    | TRY ENTER TO QUEUE    |\n");
        printf("| 3 -    | GET OUT               |\n");
        printf("+--------------------------------+\n");

        scanf("%i", &menuOption);

        if(menuOption == 1)
        {
            show(queue, limit);
        }
        else if(menuOption == 2)
        {
            char userName[20];
            int option;

            printf("Lets go! Enter your name: ");
            scanf("%s", &userName);

            printf("\nQuantity of people on queue: %i\n\n", limit );
            show(queue, limit);

            
            if(limit < 5)
            {  
                printf("\nThere is room on queue!\nDo you want to enter?\n1-yes\n2-no\n");
                scanf("%i", &option);

                if(option == 1)
                {
                    printf("\nThere are a lot of people competing for the place with you, let's see if you can do it? Your probabily was biggest then 50 percent!\n");

                    int chance = probabilytyIn();
                    if(chance > 50)
                    {
                        for(int i = 0; i < limit + 1; i++)
                        {
                            if(queue[i] == NULL)
                            {
                                queue[i] = userName;
                            }

                        }
                        limit++;
                        printf("\nYou are in queue! Your probabily was: %i", chance);
                        show(queue, limit);

                    }
                    else{

                        int givenup = givenUp(); 

                        if(givenup > 50)
                        {
                            printf("\nYour probabily was: %i, You won't be able to get in but someone left the queu, so YOU ARE IN QUEUE!\n", chance);
                            queue[limit] = userName;
                            show(queue, limit);
                        }

                        else
                        {
                            printf("\nYou are cant enterYour probabily was: %i, and noboty was given up of queue! Goodye\n", chance);
                        }
                    }
                }

                else
                {
                    printf("\nGoodBye!");
                }
            }
                
            else{

                printf("The queue is all occuped! Do you want to wait for one loser to get out of queue?\n1 - yes\n2 - no\n");

                scanf("%i", &option);

                if(option == 1)
                {
                    printf("The chance of your enter is: ");

                }

                else
                {
                    printf("Another loser, Goodbye!");
                }
            }

            }

        else if(menuOption == 3)
        {
            printf("Goodbye!");
            flag = 0;
        }  

        // Libera a memória alocada 
        for(int i = 0; i < limit; i++)
        {
            free(queue[i]);
        }

        // Libera a memória alocada para o array de ponteiros
        free(queue);
    }
    return 0;
}
