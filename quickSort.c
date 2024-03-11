#include<stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];
    int pi = low;

    for(int i = low; i < high; i++) {
        if(arr[i] <= pivot) {
            swap(&arr[i], &arr[pi]);
            pi++;
        }
    }
    swap(&arr[pi], &arr[high]);
    return pi;
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int partitionIndex = partitionArray(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, n-1);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
