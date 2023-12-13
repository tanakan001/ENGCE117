#include <stdio.h>
#include <stdlib.h>

void GetSet(int **, int *);

int main() {
    int *data, num;
    GetSet(&data, &num);

    printf("Number of elements: %d\n", num);
    printf("Elements in the set: ");
    for (int i = 0; i < num; ++i) {
        printf("%d ", data[i]);
    }

    free(data);

    return 0;
}

void GetSet(int **data, int *num) {
    printf("Enter the number of elements: ");
    scanf("%d", num);

    *data = (int *)malloc(*num * sizeof(int));

    printf("Enter the elements in the set:\n");
    for (int i = 0; i < *num; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &(*data)[i]);
    }
}
