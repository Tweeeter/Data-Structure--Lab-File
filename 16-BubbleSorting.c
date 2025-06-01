
#include <stdio.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped; // For optimization: if no two elements were swapped by inner loop, then break
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then array is sorted
        if (swapped == 0)
            break;
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

    bubbleSort(arr, n);

    printf("Array after sorting (Bubble Sort): \n");
    printArray(arr, n);

    return 0; // Indicate successful execution
}
