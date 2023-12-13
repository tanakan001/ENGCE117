#include <stdio.h>

int *GetSet(int *num)
{
    int array_size;
    printf("Enter the number of elements : ");
    scanf("%d", &array_size);

    int *array_number = new int[array_size];

    for (int i = 0; i < array_size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array_number[i]);
    }

    *num = array_size;
    return array_number;
}

int main()
{
    int *data, num;
    data = GetSet(&num);

    printf("Array elements in readable format: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}