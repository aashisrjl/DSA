#include <stdio.h>

#define MAX_VERTICES 10

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Function to initialize the adjacency matrix
void initializeGraph() {
    int i, j;

    // Initializing all elements of adjacency matrix to 0
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices
void addEdge(int u, int v) {
    // Adding edge between vertex u and vertex v (undirected graph)
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// Function to display the adjacency matrix
void displayGraph(int vertices) {
    int i, j;

    printf("Adjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, i, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: u v):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    displayGraph(vertices);

    return 0;
}

