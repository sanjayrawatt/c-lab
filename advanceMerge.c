#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays arr[l..m] and arr[m+1..r]
// and count inversions during merge
int merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int inversions = 0; // Count of inversions
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += (n1 - i); // Increment inversions
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy the remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];

    // Free temporary arrays
    free(L);
    free(R);

    return inversions;
}

// Merge Sort function to sort the array and count inversions
int mergeSort(int arr[], int l, int r) {
    int inversions = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        // Count inversions in left subarray
        inversions += mergeSort(arr, l, m);
        // Count inversions in right subarray
        inversions += mergeSort(arr, m + 1, r);
        // Merge both subarrays and count inversions
        inversions += merge(arr, l, m, r);
    }
    return inversions;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array and count inversions
    int inversions = mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of inversions: %d\n", inversions);

    free(arr);
    return 0;
}
