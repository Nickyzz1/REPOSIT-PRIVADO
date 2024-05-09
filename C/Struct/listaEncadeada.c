#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;           // Dados armazenados no nó
    struct Node* next;  // Ponteiro para o próximo nó
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória para o nó.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no início da lista
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para exibir os elementos da lista
void displayList(Node* head) {
    Node* current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;  // Inicializa a lista como vazia

    // Insere alguns elementos na lista
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Exibe os elementos da lista
    displayList(head);

    return 0;
}
