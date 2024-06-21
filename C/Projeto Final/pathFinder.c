#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUMBERS 143
#define N 12

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int dist;
} QueueNode;

typedef struct {
    QueueNode *data;
    int front, rear, size;
    unsigned capacity;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (QueueNode *) malloc(queue->capacity * sizeof(QueueNode));
    return queue;
}

int isFull(Queue* queue) { return (queue->size == queue->capacity); }

int isEmpty(Queue* queue) { return (queue->size == 0); }

void enqueue(Queue* queue, QueueNode item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size = queue->size + 1;
}

QueueNode dequeue(Queue* queue) {
    QueueNode item = { {-1, -1}, -1 }; // Return invalid item if empty
    if (isEmpty(queue)) return item;
    item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

bool isValid(int row, int col, int n) {
    return (row >= 0) && (row < n) && (col >= 0) && (col < n);
}

void BFS(int **matriz, Point start, Point end) {
    bool visited[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;
    
    visited[start.x][start.y] = true;
    Queue* queue = createQueue(N * N);
    
    QueueNode s = {start, 0};
    enqueue(queue, s);
    
    int rowNum[] = {-1, 1, 0, 0};
    int colNum[] = {0, 0, -1, 1};
    
    while (!isEmpty(queue)) {
        QueueNode curr = dequeue(queue);
        Point pt = curr.point;
        
        if (pt.x == end.x && pt.y == end.y) {
            printf("Caminho mais curto é %d passos\n", curr.dist);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            
            if (isValid(row, col, N) && matriz[row][col] == 0 && !visited[row][col]) {
                visited[row][col] = true;
                QueueNode adjCell = { {row, col}, curr.dist + 1 };
                enqueue(queue, adjCell);
            }
        }
    }
    
    printf("Não há caminho disponível.\n");
}

void generatePosition(int **matriz)
{
    srand(time(NULL));
    int YStart = rand() % 12;
    int XStart = rand() % 12;
    int YFinal = rand() % 12;
    int XFinal = rand() % 12;

    matriz[XStart][YStart] = 9;
    matriz[XFinal][YFinal] = 10;
    
    printf("\nstart col: %i, start line:  %i, final col: %i, final line %i", YStart, XStart, YFinal, XFinal);
}

void generateArena(int **matriz)
{
    int position;
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(matriz[i][j] != 9 && matriz[i][j] != 10)
            {
                position = rand() % 2;
                matriz[i][j] = position;
            }
        }
    }
}

void displayMatriz(int **matriz)
{
    printf("%s", "\n");
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            printf("%i, ",matriz[i][j]);
        }
        printf("%s", "\n");
    }
}

int main()
{
    int **matriz = malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
    {
        matriz[i] = malloc(sizeof(int) * N);
    }
    // colocando valores iniciais para a matriz
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            matriz[i][j] = 0;
        }
    }

    generatePosition(matriz);
    generateArena(matriz);
    displayMatriz(matriz);

    Point start, end;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] == 9) {
                start.x = i;
                start.y = j;
            } else if (matriz[i][j] == 10) {
                end.x = i;
                end.y = j;
            }
        }
    }
    
    BFS(matriz, start, end);

    // liberando memória
    for(int i = 0; i < N; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
