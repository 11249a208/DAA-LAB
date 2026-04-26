Aim:
To implement the Fractional Knapsack problem using a greedy approach to maximize profit based on value-to-weight ratio.

Program:
#include <stdio.h>

// Structure to store weight, value and ratio of each item
struct Item {
    int weight;
    int value;
    float ratio;
};

// Function to sort items in descending order of value/weight ratio
void sort(struct Item items[], int n) {
    struct Item temp;

    // Bubble sort based on ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input weight and value for each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items based on ratio in descending order
    sort(items, n);

    float totalProfit = 0.0;

    // Select items based on greedy approach
    for (int i = 0; i < n; i++) {

        // If full item can be taken
        if (capacity >= items[i].weight) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        } 
        else {
            // Take fractional part of item
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    // Output maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
