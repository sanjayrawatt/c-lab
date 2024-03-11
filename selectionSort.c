#include<stdio.h>

void selectionSort(int arr[], int low, int high)
{
    int i, j, min_index, temp;
    for(i = low; i < high; i++)
    {
        min_index = i;
        for(j = i+1; j <= high; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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

    selectionSort(arr, 0, n-1);
    printf("Sorted array: ");
    printArray(arr, 0, n-1);

    return 0;
}
