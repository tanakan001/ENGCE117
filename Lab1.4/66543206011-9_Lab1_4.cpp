#include <stdio.h>
int GetSet(int value[]) {
    int num;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < num; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value[i]);
    }

    return num;
}

int main() {
    int data[100];
    int num;
    num = GetSet(data);
    printf("Set elements: ");
    for (int i = 0; i < num; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
