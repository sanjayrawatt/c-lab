/* Given on array of nonnegative integers, design a linear algorithm and implement it
using a program to find whether given key element is present in the array or not. Also,
i the stal of iper of comparisons for each input case. (Time Complexity = O), where n
a) Using Iterative Approach */

// Name - Sanjay Singh Rawat, Class Roll No - 58, Section - I 
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int comparisons = 0; // Counter variable for comparisons
    int index = linearSearch(arr, n, key, &comparisons);

    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}






























