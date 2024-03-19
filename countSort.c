#include <stdio.h>
#include <stdlib.h>

// Function to perform Counting Sort
void countingSort(int arr[], int n, int range) {
    int output[n]; // Output array
    int count[range + 1], i;
    for (i = 0; i <= range; ++i)
        count[i] = 0;

    // Store count of each character
    for (i = 0; i < n; ++i)
        ++count[arr[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= range; ++i)
        count[i] += count[i - 1];

    // Build the output character array
    for (i = 0; i < n; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, range;
    printf("Enter the size of the array: ");

    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for array size.\n");
        return 1;
    }

    printf("Enter the range of elements: ");
    if (scanf("%d", &range) != 1 || range <= 0) {
        printf("Invalid input for range.\n");
        return 1;
    }

    int arr[n];
    printf("Enter the elements in the array: ");
    for(int i = 0; i < n; i++){
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for array element.\n");
            return 1;
        }
    }

    countingSort(arr, n, range);

    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}
