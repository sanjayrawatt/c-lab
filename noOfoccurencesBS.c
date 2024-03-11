#include <stdio.h>

// Function to find the leftmost occurrence of key in the array
int findLeftmost(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1; // Continue searching on the left side
        }
         else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

// Function to find the rightmost occurrence of key in the array
int findRightmost(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1; // Continue searching on the right side
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to count occurrences of key in the array
int countOccurrences(int arr[], int n, int key) {
    int leftmost = findLeftmost(arr, n, key);
    if (leftmost == -1)
        return 0; // Key not found

    int rightmost = findRightmost(arr, n, key);
    return rightmost - leftmost + 1; // Total count of occurrences
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array (sorted): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    printf("Enter the key element to search: ");
    scanf("%d", &key);

    int occurrences = countOccurrences(arr, n, key);
    if (occurrences > 0) {
        printf("%d, %d\n", key, occurrences);
    } else {
        printf("%d\n", key);
    }


    return 0;
}
