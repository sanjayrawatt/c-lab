#include<stdio.h>

void insertionSort(int arr[], int low, int high)
{
    int i, j, key;
    for (i = low + 1; i <= high; i++)
    {
        key = arr[i];
        j = i - 1;
        
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int low, int high)
{
    for(int i = low; i <= high; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in the array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, 0, n-1);
    printf("Sorted array: ");
    printArray(arr, 0, n-1);

    return 0;
}
