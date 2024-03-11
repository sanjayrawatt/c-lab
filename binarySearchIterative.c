/* Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element
is present in the array or not. Also,print the index if element found for each input case. (Time Complexity = O(log n), where n is the size of 
input)*/
// Using Iterative Way

// Name - Sanjay Singh Rawat, Class Roll No - 58, Section - I 

#include <stdio.h>

// Function to perform binary search iteratively
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Return the index if key is found
        } else if (arr[mid] < key) {
            low = mid + 1; // If key is greater, search in the right half
        } else {
            high = mid - 1; // If key is smaller, search in the left half
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

    int index = binarySearch(arr, n, key);

    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}




























