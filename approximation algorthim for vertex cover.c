Aim:
To implement an approximate solution for the Vertex Cover problem using a simple greedy approach on an undirected graph.

Program:
#include <stdio.h>

#define V 5  // Number of vertices

// Function to find an approximate vertex cover
void findVertexCover(int graph[V][V]) 
{ 
    int visited[V];

    // Initialize all vertices as not included in cover
    for (int i = 0; i < V; i++) 
    { 
        visited[i] = 0; 
    } 

    // Traverse all edges of the graph
    for (int u = 0; u < V; u++) 
    { 
        for (int v = u + 1; v < V; v++)   
        { 
            // If there is an edge between u and v
            if (graph[u][v] == 1) 
            { 
                // Include both vertices in the cover
                visited[u] = 1; 
                visited[v] = 1; 
            } 
        } 
    } 

    printf("Approximate Vertex Cover: "); 

    int count = 0; 

    // Print vertices included in the cover
    for (int i = 0; i < V; i++) 
    { 
        if (visited[i]) 
        { 
            printf("%d ", i); 
            count++; 
        } 
    } 

    // Print total number of vertices in the cover
    printf("\nTotal vertices in the cover: %d\n", count);
} 

int main() 
{ 
    // Adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 1, 0, 0, 0}, 
        {1, 0, 1, 1, 0}, 
        {0, 1, 0, 1, 1}, 
        {0, 1, 1, 0, 1}, 
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n"); 

    // Call function to find vertex cover
    findVertexCover(graph); 

    return 0; 
}
