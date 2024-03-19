#include <stdio.h>
#include <string.h>

// Function to perform bubble sort on an array of strings
void bubbleSort(char arr[][100], int n) {
    int i, j;
    char temp[100];
    int swapped;

    for (i = 0; i < n - 1; i++) {
 
        for (j = 0; j < n - i - 1; j++) {

            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                swapped = 1; 
            }
        }

        if (swapped == 0)
            break;
    }
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char strings[n][100];

    // Input the strings
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    // Display original array
    printf("\nOriginal array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // Perform bubble sort
    bubbleSort(strings, n);

    // Display sorted array
    printf("\nSorted array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
