#include <stdio.h>

int *GetMatrix( int *row, int *col ) ;

int main() {
    int *data, m, n ;
    data = GetMatrix( &m, &n );
    delete[] data;
    return 0 ;
}

int *GetMatrix( int *row, int *col ) {

    int *a;

    printf("Row : ");
    scanf("%d",  row);

    printf("Col : ");
    scanf("%d" , col);

    a = new int [*row * *col];

    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *col; j++)
        {
            printf("Number Columns : ( %d | %d ) \n" , i + 1 , j + 1 );
             printf("Add Data : ");
             scanf("%d", &a[i * (*col) +j]);
        }      
    }
    printf("row : %d " ,*row);
    printf("col : %d " ,*col);
    printf("\n");
    for (int i = 0; i < *row; i++){
        for (int j = 0; j < *col; j++)
        {
            printf("| %d | " , a[i * (*col) +j]);
        }
        printf("\n");
    }
    

}