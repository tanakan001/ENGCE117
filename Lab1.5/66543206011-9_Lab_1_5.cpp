#include <stdio.h>

void GetMatrix(int value[][100], int *row, int *col)
{
    printf("Enter the number of rows: ");
    scanf("%d", row);

    printf("Enter the number of columns: ");
    scanf("%d", col);

    for (int i = 0; i < *row; ++i)
    {
        for (int j = 0; j < *col; ++j)
        {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &value[i][j]);
        }
    }
}

int main()
{
    int data[100][100], m, n;

    GetMatrix(data, &m, &n);

    printf("Matrix elements:\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}