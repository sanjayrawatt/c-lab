//  Design an algorithm and write a program to find the n" term of Fibonacci series using Recursion

// Name - Sanjay Singh Rawat, Class Roll No - 58, Section - I 

#include <stdio.h>

// Function to find the nth term of Fibonacci series recursively
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case: if n is 0 or 1, return n
    }
    // Recursive case: nth term is the sum of (n-1)th and (n-2)th terms
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the value of n to find the nth Fibonacci term: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    printf("The %dth term of Fibonacci series is: %d\n", n, fibonacci(n));

    return 0;
}



























