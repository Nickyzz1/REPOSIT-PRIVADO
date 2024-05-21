#include <stdio.h>
#include <stdio.h>

struct Item{
    
    int item;
    int size;
    struct Item *next;
};

struct Item *addItem(struct Item *list, int value) {
    struct Item *newItem = (struct Item *)malloc(sizeof(struct Item)); // Aloca memória para o novo item

    if (newItem == NULL) {
        printf("Exception - Error memory allocation");
    } else {
        newItem->item = value; // Coloca valor no item
        newItem->next = NULL; // O próximo sempre será NULL, pois o que adicionaremos sempre será o último da lista

        // Se a lista estiver vazia, o novo item será o primeiro da lista
        if (list == NULL) {
            list = newItem;
            list->size = 1; // Inicializa o tamanho da lista como 1
        } else {
            // Encontra o último item da lista e adiciona o novo item ao final
            struct Item *current = list;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newItem;
            list->size++; // Incrementa o tamanho da lista
        }
    }

    return list;
}


int getSize(struct Item *list)
{
    int size = 0;
    struct Item *current = list;
    while(current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}

//mostra os itens
void display(struct Item * list, int size)
{
    if(size == 0)
    {
        printf("The linked list is empty...");
        return;
    }
    else
    {
        struct Item *current = list; //o ponteiro current aponta para os ponteiros que list aponta
        printf("The linked list:\n");
        while(current != 0)
        {
            printf("[%i] ", current->item); //mostra o item que está no ponteiro quye current aponta

            current = current->next; //avança para o próx item
        }
        printf("%s", "\n");
    }
}

int main()
{
    int value;
    struct Item *list = NULL;

    printf("Enter a value to add :");
    scanf("%i", &value);

    list = addItem(list, value);
    int size = getSize(list);
    printf("\nSize of list: %i\n", size);
    display(list, size);

    free(list);

}

//Os elementos de uma lista podem ser removidos, a semelhança das regras de
// inserção, de três maneiras distintas:
// a) Remoção do primeiro elemento da lista;
// b) Remoção do último elemento da lista;
// c) Remoção de um elemento em uma posição arbitrária.

//add, that's create the linked list
//cria o espaço para um novo item: struct Item *newItem = malloc(sizeof(struct Item));
//se der erro a criação desse espaço retorna algo
//se não der erro a alocação desse espaço ela coloca o valor, recebido de par^^ametro na função, dentro do novo item reviamente criado na etapa um
//por fim aponta o next para o próximo item

// criao struct veiculo

// veiculo *listaveiculo = null;


// listaveiculos = addveiculo(listaveiculo, 2005)
// display(listaveículos)


// void displçay(veiculo *p)
// {
// if(p)
// {

// do
// 	print("%i",p->ano)

// while(p)

// else{
// 	print(lista vazia)


// addVeiculo(veiculo *listaveiculo)
// {





