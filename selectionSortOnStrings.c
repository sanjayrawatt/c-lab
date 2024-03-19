#include <stdio.h>
#include <string.h>

// Function to perform selection sort on an array of strings
void selectionSort(char arr[][100], int n) {
    int i, j, min_idx;
    char temp[100];

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            // Compare adjacent strings lexicographically
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
    }
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Clear input buffer
    while (getchar() != '\n');

    char strings[n][100];

    // Input the strings
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(strings[i], 100, stdin);
        // Remove trailing newline if present
        if (strings[i][strlen(strings[i]) - 1] == '\n')
            strings[i][strlen(strings[i]) - 1] = '\0';
    }

    // Display original array
    printf("\nOriginal array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // Perform selection sort
    selectionSort(strings, n);

    // Display sorted array
    printf("\nSorted array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
