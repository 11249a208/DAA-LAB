Aim:
To implement the Best Fit algorithm for the Bin Packing problem, where items are placed into bins such that each item is assigned to the bin with the least remaining space that can still accommodate it, thereby minimizing the number of bins used.

Program:
#include <stdio.h>

// Function to implement Best Fit Bin Packing algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    // Array to store remaining capacity of each bin
    int bin[n];

    // Variable to keep track of number of bins used
    int binCount = 0;

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Traverse through each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;           // Index of best bin for current item
        int minSpace = capacity + 1;  // Minimum leftover space after placement

        // Find the best bin that can accommodate the item
        for (int j = 0; j < binCount; j++)
        {
            // Check if item fits and leaves minimum unused space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If a suitable bin is found, place the item
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // Reduce available space in bin
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create a new bin if no suitable bin is found
            bin[binCount] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++; // Increase bin count
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity, itemSize;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    int items[n]; // Array to store item sizes

    printf("Enter item sizes:\n");

    // Input item sizes
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Validate item size (must not exceed bin capacity)
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--; // Repeat input for same item
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);

    return 0;
}
