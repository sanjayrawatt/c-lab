#include<stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
   if(low < high)
    {
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    printf("enter the size of the array : ");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements in array : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}