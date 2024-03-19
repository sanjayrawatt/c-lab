#include <stdio.h>
#include <string.h>

// Function to perform insertion sort on an array of strings
void insertionSort(char arr[][100], int n) {
    int i, j;
    char key[100];

    for (i = 1; i < n; i++) {
        strcpy(key, arr[i]);
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j = j - 1;
        }
        strcpy(arr[j + 1], key);
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

    // Perform insertion sort
    insertionSort(strings, n);

    // Display sorted array
    printf("\nSorted array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
