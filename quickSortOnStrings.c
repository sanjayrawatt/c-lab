#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char arr[][100], int a, int b);
int partition(char arr[][100], int low, int high);
void quickSort(char arr[][100], int low, int high);

void swap(char arr[][100], int a, int b) {
    char temp[100];
    strcpy(temp, arr[a]);
    strcpy(arr[a], arr[b]);
    strcpy(arr[b], temp);
}

int partition(char arr[][100], int low, int high) {
    char pivot[100];
    strcpy(pivot, arr[high]);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quickSort(char arr[][100], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Perform quick sort
    quickSort(strings, 0, n - 1);

    // Display sorted array
    printf("\nSorted array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
