
#include <stdio.h>

// Function to implement Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    printf("Array after sorting (Insertion Sort): \n");
    printArray(arr, n);

    return 0; // Indicate successful execution
}

