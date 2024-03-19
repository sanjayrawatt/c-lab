#include <stdio.h>

// Binary search to find the index of key in the array
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Key not found
}

// Function to find three indices i, j, k such that arr[i] + arr[j] = arr[k]
void findIndices(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = binarySearch(arr, j + 1, n - 1, arr[i] + arr[j]);
            if (k != -1) {
                printf("Indices found: i = %d, j = %d, k = %d\n", i, j, k);
                return; // Return after finding the first occurrence
            }
        }
    }
    printf("No such indices exist\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in the sorted array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findIndices(arr, n);
    return 0;
}
