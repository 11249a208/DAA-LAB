Aim:
To implement Kruskal’s Algorithm to find the Minimum Spanning Tree (MST) of a weighted graph using the Union-Find technique.

Program:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Number of vertices and edges
#define V  5
#define E  6

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Array for Union-Find (Disjoint Set)
int parentUF[V];

// Function to find the root of a set (with recursion)
int find(int i)
{
    if (parentUF[i] == i)
        return i;

    return find(parentUF[i]);
}

// Function to perform union of two sets
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

    // Attach one tree under another
    parentUF[rootU] = rootV;
}

// Comparator function for sorting edges by weight
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to implement Kruskal's Algorithm
void kruskalMST(struct Edge edges[])
{
    printf("\nKruskal's MST:\n");
    printf("Edge \tWeight\n");

    // Sort edges in increasing order of weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
        parentUF[i] = i;

    int count = 0; // Number of edges included in MST
    int total = 0; // Total weight of MST

    // Iterate through sorted edges
    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        // Check if adding edge forms a cycle
        if (find(u) != find(v))
        {
            // Include edge in MST
            printf("%d - %d \t%d\n", u, v, edges[i].weight);

            total += edges[i].weight;

            // Union the sets
            unionSet(u, v);

            count++;
        }
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

int main()
{
    // Initialize graph edges
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}
    };

    // Call Kruskal's MST function
    kruskalMST(edges);

    return 0;
}
