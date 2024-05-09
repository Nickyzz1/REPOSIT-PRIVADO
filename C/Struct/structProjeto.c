#include <stdio.h>
#include <stdlib.h>

//na lista encadeada os itens são adicionaos ao inicio: pr exe, tempo a lista: A, B, C, D--> se formos adc ouro item:
//lista: E, A, B, C, D  
//o primeiro na vrdd é o último que chegou a fila

typedef struct {
    char name[9];
    char email[50];
    char address[50];
    char birth[8];
    char obs[200];
    int phone;
} Telefone;

typedef struct Node {
    Telefone data;
    struct Node *next; // o next é um ponteiro para a estrutura inteira do Node
} Node;

Node *createNode(Telefone data) {

    Node *newNode = malloc(sizeof(Node)); // aloca memória para um nó do tamanho necessário
    newNode->data = data; //atribui dados ao novo novo membro nó, coloca os dados desse telefone no dado;
    newNode->next = NULL;

    return newNode; //que agora tem um valor
}

void insertAtBeginning(Node **head, Telefone data) { //dois poonteiros pois o objetivos é mudar o ponteiro que aponta para o inicio da lsiatencadeada
    Node *newNode = createNode(data); //adc a var newNode o nó criado
    newNode->next = *head; //next aponta para o mesmo valor que o ponteiro de head aponta antes de ser adicionado um novo item no início da lista;
    *head = newNode; //head agora aponta para outro valor, o newNode;
}

void displayList(Node *head) { //recebe um ponteiro para o endereço de memória de head, priemiro intem da lista encadeada
    Node *current = head; //o pointer de current apnta para o valor de head
    printf("Lista: "); 
    while (current != NULL) {
        printf( current->data.name); //nome aramazenado no nnó atual da iteração //data.name é um dado que acessa o nome definido na struct que, por sua vez, pertecece ao objeto nó atual
        printf("%s   %i   %s   %s   %s   %s ", current->data.name, current->data.phone, current->data.email, current->data.address, current->data.birth, current->data.obs);
        current = current->next; //current é atualizado para mostrar o valor após o atual
        printf("%s", "\n\n");
    }
}

int main() {
    Node *head = NULL;
    int option;

    // Cria alguns objetos Telefone
    Telefone tel1 = {"Alice", "alice@example.com", "123 Main St", "01012000", "", 12345};
    Telefone tel2 = {"Bob", "bob@example.com", "456 Elm St", "02022002", "", 67890};
    Telefone tel3 = {"Charlie", "charlie@example.com", "789 Oak St", "03032003", "", 13579};

    // Insere os objetos Telefone na lista
    insertAtBeginning(&head, tel1);
    insertAtBeginning(&head, tel2);
    insertAtBeginning(&head, tel3);

    printf("------------------------------------------------\n");
    printf("|------------------BEM VINDO--------------------|\n");
    printf("|---------------DIGITE A OPCAO------------------|\n");
    printf("|1 - BUSCAR CONTATO                             |\n");
    printf("|2 - BUSCAR ANIVERSARIO POR DIA E MES           |\n"); //ORDEM ALFABÉTICA
    printf("|3 - INSERIR PESSOA                             |\n");
    printf("|4 - RETIRAR PESSOA                             |\n");
    printf("|5 - MOSTRAR AGENDA                             |\n\n");
    scanf("%i", &option);

    // Exibe os elementos da lista
    switch (option)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
    displayList(head);

    return 0;
}

// ) Definir a estrutura acima.
// (b) Declarar a variável agenda (vetor) com capacidade de agendar vários contatos. A cada contato que será inserido, será alocada memória apenas para mais um contato.
// (c) Definir um bloco de instruções busca por primeiro nome: Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas).
// (d) Definir um bloco de instruções busca por mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse mês.
// (e) Definir um bloco de instruções busca por dia e mês de aniversário: Imprime os dados de todas as pessoas que fazem aniversário nesse dia e mês.
// (f) Definir um bloco de instruções insere pessoa: Insere por ordem alfabética de nome.
// (g) Definir um bloco de instruções retira pessoa: Retira todos os dados dessa pessoa e desloca todos os elementos seguintes do vetor para a posição anterior.
// (h) Definir um bloco de instruções imprime agenda com as opções: