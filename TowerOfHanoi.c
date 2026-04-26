Aim:
To implement the Tower of Hanoi problem using recursion to move disks from source to destination following the given rules.

Program:
#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void toh(int diskcount, char s, char d, char t){
    
    // Base case: only one disk to move
    if (diskcount == 1)
    {
        printf("\nMove disk %d from %c to %c", diskcount, s, d);
        return;
    }

    // Step 1: Move n-1 disks from source to temporary rod
    toh(diskcount - 1, s, t, d);

    // Step 2: Move the nth disk from source to destination
    printf("\nMove disk %d from %c to %c", diskcount, s, d);

    // Step 3: Move n-1 disks from temporary rod to destination
    toh(diskcount - 1, t, d, s);
}

int main() {
    int n;

    // Input number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Call Tower of Hanoi function
    toh(n, 'S', 'D', 'T');

    return 0;
}
