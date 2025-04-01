#include <stdio.h>

int main()
{
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    // Input first matrix
    int matrixA[n][n], matrixB[n][n], add[n][n], multiply[n][n];
    printf("Input elements for matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    // Input second matrix
    printf("Input elements for matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("B[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }
    // Addition of matrices
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            add[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    // Result of addition
    printf("Addition of Matrix A and Matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", add[i][j]);
        }
        printf("\n");
    }
    // Multiplication of matrices
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            multiply[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                multiply[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Result of multiplication
    printf("Multiplication of Matrix A and Matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", multiply[i][j]);
        }
        printf("\n");
    }

    return 0;
}