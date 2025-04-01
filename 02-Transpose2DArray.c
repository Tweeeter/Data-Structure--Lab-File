#include <stdio.h>

int main()
{
    int ROWS, COLS;

    // Input number of rows and columns
    printf("Enter number of rows of matrix : ");
    scanf("%d", &ROWS);
    printf("Enter number of columns of matrix : ");
    scanf("%d", &COLS);

    // Create matrices with sizes from user input
    int matrix[ROWS][COLS], transpose[COLS][ROWS];

    // Function to input matrices
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print Original matrix
    printf("Original matrix is : \n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculating the transpose of the matrix
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Print Transposed matrix
    printf("Transposed matrix is : \n");
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            printf("%d \t", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}