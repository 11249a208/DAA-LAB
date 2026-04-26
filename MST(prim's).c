Aim:
To implement Prim’s Algorithm to find the Minimum Spanning Tree (MST) of a weighted graph using a greedy approach.

Program:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Number of vertices and edges
#define V 5
#define E 6

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[])
{
    int min = INT_MAX, min_index;

    // Find the unvisited vertex with the smallest key value
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the MST and calculate total cost
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    // Print edges and accumulate total weight
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", total);
}

// Function to implement Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Stores constructed MST
    int key[V];      // Key values used to pick minimum weight edge
    int visited[V];  // Tracks included vertices in MST

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1; // First node is root of MST

    // Construct MST with V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick minimum key vertex not yet included
        int u = minKey(key, visited);

        visited[u] = 1;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Update only if:
            // 1. Edge exists
            // 2. Vertex not yet included
            // 3. Weight is smaller than current key
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the resulting MST
    printPrimMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    // Call Prim's Algorithm
    primMST(graph);

    return 0;
}
