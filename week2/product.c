#include <stdio.h>
#include <stdlib.h>

void accept(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", (*(a + i) + j));
}

void product(int **a, int **b, int **p, int r, int c, int n)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(p + i) + j) = 0;

            for (int k = 0; k < c; k++)
            {
                *(*(p + i) + j) +=
                    (*(*(a + i) + k)) * (*(*(b + k) + j));
            }
        }
    }
}

void display(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%4d", *(*(a + i) + j));

        printf("\n");
    }
}

int** allocateMatrix(int r, int c) {
    int **mat = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        *(mat + i) = (int *)malloc(c * sizeof(int));
    return mat;
}

void freeMatrix(int **mat, int r) {
    for (int i = 0; i < r; i++)
        free(*(mat + i));
    free(mat);
}

int main()
{
    int r, c, m, n;

    printf("Enter rows and columns of A: ");
    scanf("%d%d", &r, &c);

    printf("Enter rows and columns of B: ");
    scanf("%d%d", &m, &n);

    if (c != m)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int **A = allocateMatrix(r, c);
    int **B = allocateMatrix(m, n);
    int **P = allocateMatrix(r, n);

    printf("Enter Matrix A:\n");
    accept(A, r, c);

    printf("Enter Matrix B:\n");
    accept(B, m, n);

    product(A, B, P, r, c, n);

    printf("\nProduct Matrix:\n");
    display(P, r, n);

    freeMatrix(A, r);
    freeMatrix(B, m);
    freeMatrix(P, r);

    return 0;
}
