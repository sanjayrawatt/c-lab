#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char arr[][100], int l, int m, int r);
void mergeSort(char arr[][100], int l, int r);

void merge(char arr[][100], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    char L[n1][100], R[n2][100];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[l + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[m + 1 + j]);

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        // Compare strings lexicographically
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][100], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
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

    // Perform merge sort
    mergeSort(strings, 0, n - 1);

    // Display sorted array
    printf("\nSorted array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
