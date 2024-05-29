#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[10];
    int age;
    struct Node *next;
};
//lembrra que char é uma lista de caracteres e deve ser passado com um ponteiro assim como uma lista
//o tipo da função add tem que ser do tipo sa struct
struct Node* add(struct Node *list, char *name, int age, int size)
{
    struct Node *item = (struct Node*)malloc(sizeof(struct Node));

    if(item == NULL)
    {
        printf("\nError on memory allocate\n");
    } 
    else {
        if(list == NULL)
        {
            strcpy(item->name, name);
            item->age = age;
            size++;
        }
        else{
            struct Node *temp = item;
            strcpy(item->name, name);
            item->age = age;
            item->next = temp;
            size++;
            return item;
        }
    }
}


void display(struct Node *list)
{
    struct Node *current = list;
    while(current != NULL)
    {
        printf("[%s]", current->name);
        printf("[%d]", current->age);
        current = current->next;
    }
}

void freeList(struct Node *list)
{
    struct Node *temp;
    while(list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

int main()
{
    int size = 0;
    char name[10];
    int age;

    struct Node *list = NULL;
    int fla = 1;

    while(fla == 1)
    {
        printf("\nENTER A NAME:");
        scanf("%s", name);
        printf("\nENTER AN AGE:");
        scanf("%d", &age);

        list = add(list, name, age, size);
        display(list);
    }
    free(list);
}

// 1 - Desenvolva os métodos de pilha e fila para lista encadeada(com e sem cabeçalho).
// 2 - Escreva uma função que copie um vetor para uma lista encadeada  
// 3 - Escreva uma função que copie uma lista encadeada para um vetor


// 4 - Escreva uma função que verifica se duas listas dadas são iguais, ou melhor, se
// têm o mesmo conteúdo
