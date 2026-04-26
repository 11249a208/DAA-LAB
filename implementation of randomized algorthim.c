Aim:
To implement the Quick Sort algorithm using a randomized pivot to efficiently sort an array of integers.

Program:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place pivot at correct position
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Choose last element as pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot at correct position
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

// Quick Sort function using randomized pivot
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Generate random index for pivot
        int randomIndex = low + rand() % (high - low + 1);

        // Swap random element with last element (pivot)
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    // Seed random number generator
    srand(time(NULL));

    // Input number of elements
    printf("Enter number of elements: ");

    // Validate input
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbersToSort[i]);

    // Call Quick Sort
    quickSort(numbersToSort, 0, n - 1);

    // Print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", numbersToSort[i]);

    return 0;
}
