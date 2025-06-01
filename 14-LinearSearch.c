
#include <stdio.h>

int main() {
    int n, i, key, found = 0, position = -1;

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

    // Input the element to search
    printf("Enter the element to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input for the search key. Please enter an integer.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return 1; // Indicate an error
    }

    // Perform Linear Search
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            position = i + 1; // Store 1-based position
            break; // Element found, no need to search further
        }
    }

    // Display the result
    if (found) {
        printf("Element %d found at position %d.\n", key, position);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0; // Indicate successful execution
}
