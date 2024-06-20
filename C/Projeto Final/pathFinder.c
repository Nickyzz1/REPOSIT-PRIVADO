#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99999 //valor infinito para comparações de distancias
#define MAX_NODES 100

typedef struct {
    int node;
    int cost;
} Edge;

typedef struct {
    Edge edges[MAX_NODES]; // Lista de arestas
    int num_edges;         // Número de arestas saindo deste nó
} GraphNode;

typedef struct {
    GraphNode nodes[MAX_NODES]; // Lista de nós do grafo
    int num_nodes;              // Número de nós no grafo
} Graph;

// Função para inicializar o grafo
void initialize_graph(Graph *graph, int num_nodes) {
    graph->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; ++i) {
        graph->nodes[i].num_edges = 0;
    }
}

// Função para adicionar uma aresta direcionada no grafo
void add_edge(Graph *graph, int from, int to, int cost) {
    int num_edges = graph->nodes[from].num_edges;
    graph->nodes[from].edges[num_edges].node = to;
    graph->nodes[from].edges[num_edges].cost = cost;
    graph->nodes[from].num_edges++;
}

// Algoritmo A* para encontrar o caminho mais curto de start para goal
void a_star(Graph *graph, int start, int goal) {
    // Vetor de distâncias mínimas estimadas (heurísticas) do nó inicial até cada nó
    int heuristic[MAX_NODES];
    for (int i = 0; i < graph->num_nodes; ++i) {
        heuristic[i] = INF; // Inicializa todas as distâncias como infinito
    }
    heuristic[start] = 0; // A distância do nó inicial até ele mesmo é zero
    
    // Vetor de custo total do caminho do nó inicial até cada nó
    int cost_so_far[MAX_NODES];
    for (int i = 0; i < graph->num_nodes; ++i) {
        cost_so_far[i] = INF; // Inicializa todos os custos como infinito
    }
    cost_so_far[start] = 0; // O custo do caminho do nó inicial até ele mesmo é zero
    
    // Estrutura para armazenar os nós a serem explorados
    int open_set[MAX_NODES];
    int open_set_size = 1;
    open_set[0] = start;
    
    // Vetor de nós visitados
    bool visited[MAX_NODES] = {false};
    
    while (open_set_size > 0) {
        // Encontra o nó no open set com o menor custo estimado (heurístico)
        int current = open_set[0];
        int current_index = 0;
        for (int i = 1; i < open_set_size; ++i) {
            if (heuristic[open_set[i]] < heuristic[current]) {
                current = open_set[i];
                current_index = i;
            }
        }
        
        // Remove o nó atual do open set
        open_set[current_index] = open_set[open_set_size - 1];
        open_set_size--;
        
        // Se o nó atual é o goal, terminamos
        if (current == goal) {
            break;
        }
        
        // Marca o nó atual como visitado
        visited[current] = true;
        
        // Percorre os vizinhos do nó atual
        for (int i = 0; i < graph->nodes[current].num_edges; ++i) {
            int neighbor = graph->nodes[current].edges[i].node;
            int new_cost = cost_so_far[current] + graph->nodes[current].edges[i].cost;
            
            // Se o novo caminho encontrado até o vizinho é melhor
            if (new_cost < cost_so_far[neighbor]) {
                cost_so_far[neighbor] = new_cost;
                heuristic[neighbor] = new_cost; // Aqui poderia ser uma heurística mais sofisticada
                if (!visited[neighbor]) {
                    open_set[open_set_size] = neighbor;
                    open_set_size++;
                }
            }
        }
    }
    
    // Exibe o caminho mais curto encontrado
    printf("Caminho mais curto de %d para %d: %d\n", start, goal, cost_so_far[goal]);
}

int main() {
    Graph graph;
    int num_nodes = 6;
    initialize_graph(&graph, num_nodes);
    
    // Exemplo de adição de arestas no grafo
    add_edge(&graph, 0, 1, 5);
    add_edge(&graph, 0, 2, 10);
    add_edge(&graph, 1, 3, 3);
    add_edge(&graph, 2, 3, 1);
    add_edge(&graph, 3, 4, 5);
    add_edge(&graph, 2, 4, 8);
    add_edge(&graph, 4, 5, 2);
    
    int start = 0;
    int goal = 5;
    
    // Encontra o caminho mais curto usando o algoritmo A*
    a_star(&graph, start, goal);
    
    return 0;
}
