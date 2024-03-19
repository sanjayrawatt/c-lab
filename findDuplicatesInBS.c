#include <stdio.h>

// Function to find the leftmost occurrence of key
int findLeftmost(int arr[], int n, int key) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            result = mid;
            right = mid - 1; // Continue searching on the left side
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Function to find the rightmost occurrence of key
int findRightmost(int arr[], int n, int key) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            result = mid;
            left = mid + 1; // Continue searching on the right side
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Main function to search for key and find the number of copies
void searchAndCount(int arr[], int n, int key) {
    int leftmost = findLeftmost(arr, n, key);
    if (leftmost == -1) {
        printf("Element not found\n");
        return;
    }
    int rightmost = findRightmost(arr, n, key);
    int count = rightmost - leftmost + 1;
    printf("Element %d found %d times\n", key, count);
}

int main() {
    int n;
    printf("enter the size of the array : ");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements in the array : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("enter the element to be searched : ");
    scanf("%d", &key);

    searchAndCount(arr, n, key);
    return 0;
}
