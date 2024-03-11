#include <stdio.h>
#include <math.h>

// Function to perform Jump Search
int jumpSearch(int arr[], int n, int key, int *comparisons) {
    int step = sqrt(n);
    int prev = 0;

    // Jumping ahead until we find an interval where key might be present
    while (prev < n && arr[prev] < key) {
        prev += step;
        (*comparisons)++;

        // If we've reached the end of the array or passed the key element
        if (prev >= n || arr[prev] >= key)
            break;
    }

    // Perform linear search in the interval [prev - step, min(prev, n)]
    for (int i = prev - step; i < prev && i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key)
            return i;
    }

    return -1; // Key not found
}

int main() {
    int T;
    printf("enter the number of test cases : ");
    scanf("%d", &T); // Read number of test cases

    while (T--) {
        int n;
        scanf("%d", &n); // Read size of array
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]); // Read array elements

        int key;
        scanf("%d", &key); // Read key element to search

        int comparisons = 0;
        int index = jumpSearch(arr, n, key, &comparisons);

        if (index != -1) {
            printf("Present %d\n", comparisons);
        } else {
            printf("Not Present %d\n", comparisons);
        }
    }

    return 0;
}
