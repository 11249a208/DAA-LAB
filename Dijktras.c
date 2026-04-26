Aim:
To implement Dijkstra's Algorithm to find the shortest path from a source vertex to all other vertices in a weighted graph.

Program:
#include <stdio.h>

// Number of vertices in the graph
#define V 5

// Define a large value to represent infinity
#define INF 999999

// Function to find the vertex with minimum distance value
// from the set of vertices not yet included in shortest path tree
int extractMin(int dist[], int visited[]) 
{ 
    int min = INF, min_index = -1;

    // Loop through all vertices to find the minimum distance
    for (int v = 0; v < V; v++) 
    { 
        if (!visited[v] && dist[v] <= min) 
        {
            min = dist[v]; 
            min_index = v; 
        } 
    } 
    return min_index; 
} 

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V]) 
{ 
    int dist[V];     // Array to store shortest distances from source
    int visited[V];  // Array to track visited vertices

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < V; i++) 
    { 
        dist[i] = INF; 
        visited[i] = 0;
    } 

    // Distance of source vertex (vertex 0) is always 0
    dist[0] = 0;

    // Loop to find shortest path for all vertices
    for (int count = 0; count < V; count++) 
    { 
        // Pick the minimum distance vertex not yet processed
        int u = extractMin(dist, visited);

        // If no such vertex is found, break
        if (u == -1) 
            break;

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update distance value of adjacent vertices
        for (int j = 0; j < V; j++) 
        { 
            // Update only if:
            // 1. There is an edge (graph[u][j] > 0)
            // 2. Vertex is not visited
            if (graph[u][j] > 0 && !visited[j]) 
            { 
                // Check if new distance is shorter
                if (dist[j] > dist[u] + graph[u][j]) 
                {
                    dist[j] = dist[u] + graph[u][j]; 
                } 
            }
        } 
    } 

    // Print the shortest distances from source
    printf("\nVertex \t Distance from Source (0)\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d --> %d\n", i, dist[i]); 
} 

int main() 
{ 
    // Adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 10, 0, 30, 100}, 
        {10, 0, 50, 0, 0}, 
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60}, 
        {100, 0, 10, 60, 0}
    }; 

    // Call Dijkstra function
    dijkstra(graph); 

    return 0; 
}
