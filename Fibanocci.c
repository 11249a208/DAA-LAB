Aim:
To implement a recursive function to find the nth term in the Fibonacci sequence.

Program:
#include <stdio.h>

// Recursive function to find nth Fibonacci term
int fib(int n){  
    // Base case: fib(0) = 0
    if (n == 0){
        return 0;
    }

    // Base case: fib(1) = 1
    if (n == 1) {
        return 1;
    }

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n-1) + fib(n-2); 
}  

int main() {
    int n;

    // Input number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n < 0){
        printf("Invalid number");
        return 0;
    }

    // Display nth Fibonacci term
    printf("Fibonacci term is: %d", fib(n));

    return 0;
}
