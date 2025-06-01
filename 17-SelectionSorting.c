
#include <stdio.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to implement Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        // of the unsorted part of the array, if it's not already in place.
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for the number of elements. Please enter a positive integer.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return 1; // Indicate an error
    }

    int arr[n]; // Declare array using VLA (Variable Length Array)

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for element %d. Please enter integers only.\n", i + 1);
            // Clear the input buffer
            while (getchar() != '\n');
            return 1; // Indicate an error
        }
    }

    printf("Array before sorting: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array after sorting (Selection Sort): \n");
    printArray(arr, n);

    return 0; // Indicate successful execution
}

