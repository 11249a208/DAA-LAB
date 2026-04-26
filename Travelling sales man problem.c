Aim:
To implement the Travelling Salesman Problem (TSP) using dynamic programming and bit masking to find the minimum travelling cost.

Program:
#include <stdio.h>
#include <limits.h>
#define MAXN 15          //Maximum number of cities
#define INF INT_MAX      // Represent infinity

int n;                  // Number of cities
int d[MAXN][MAXN];     // Cost matrix
int dp[MAXN][1 << MAXN]; // DP table for memoization

// Recursive function to compute minimum cost
int g(int i, int s)
{
    // Base case: if no cities left, return cost to go back to start
    if (s == 0)
        return d[i][0];

    // Return already computed result
    if (dp[i][s] != -1)
        return dp[i][s];

    int mincost = INF;

    // Try all possible next cities
    for (int k = 0; k < n; k++)
    {
        // Check if city k is in set s
        if (s & (1 << k))
        {
            // Calculate cost of going to city k
            int cost = d[i][k] + g(k, s & ~(1 << k));

            // Update minimum cost
            if (cost < mincost)
            {
                mincost = cost;
            }
        }
    }

    // Store result in DP table
    return dp[i][s] = mincost;
}

int main()
{
    // Input number of cities
    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize DP table with -1
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][mask] = -1;

    // Create set of cities excluding starting city (0)
    int S = 0;
    for (int i = 1; i < n; i++)
        S |= (1 << i);

    // Call recursive function starting from city 0
    int result = g(0, S);

    // Print the given cost matrix
    printf("\nGiven Cost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
        printf("|\n");
    }

    // Output minimum travelling cost
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
