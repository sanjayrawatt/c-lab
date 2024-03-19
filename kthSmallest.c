#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to partition the array and return the index of the pivot
int partition(int arr[], int low, int high) {
    // Choose a random pivot element
    srand(time(NULL));
    int randomIndex = low + rand() % (high - low + 1);
    int pivot = arr[randomIndex];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (pivot element)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to find the Kth smallest element in the array
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // If pivot index is the Kth element, return it
        if (pi == k - 1)
            return arr[pi];
        // If Kth element is less than pivot, recurse on the left subarray
        else if (k - 1 < pi)
            return quickSelect(arr, low, pi - 1, k);
        // Else, recurse on the right subarray
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    // If K is out of range, return -1
    return -1;
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid value of K\n");
    } else {
        int kthSmallest = quickSelect(arr, 0, n - 1, k);
        if (kthSmallest != -1) {
            printf("The %dth smallest element is: %d\n", k, kthSmallest);
        } else {
            printf("Invalid value of K\n");
        }
    }

    free(arr);
    return 0;
}
