#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to partition the array and return the index of the pivot
int partition(int arr[], int low, int high, int *comparisons, int *swaps) {
    // Choose a random pivot element
    srand(time(NULL));
    int randomIndex = low + rand() % (high - low + 1);
    int pivot = arr[randomIndex];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            (*swaps)++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    (*swaps)++;
    // Swap arr[i + 1] and arr[high] (pivot element)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to perform Quick Sort and count comparisons and swaps
void quickSort(int arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high, comparisons, swaps);

        // Recursively sort the left and right subarrays
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
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

    int comparisons = 0, swaps = 0;
    quickSort(arr, 0, n - 1, &comparisons, &swaps);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    free(arr);
    return 0;
}
