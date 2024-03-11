/* Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element
is present in the array or not. Also,print the index if element found for each input case. (Time Complexity = O(log n), where n is the size of 
input)*/
// Using Recursive Way

// Name - Sanjay Singh Rawat, Class Roll No - 58, Section - I 

#include <stdio.h>

// Function to perform binary search recursively
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return mid; // Return the index if key is found
        } else if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, high, key); // Search in the right half
        } else {
            return binarySearchRecursive(arr, low, mid - 1, key); // Search in the left half
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int index = binarySearchRecursive(arr, 0, n - 1, key);

    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}






























