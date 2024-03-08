#include <stdio.h>

int BinSearch(int arr[], int n, int key);

int main() {
    int data[6] = {1, 2, 3, 4, 5, 7};
    int n = 6;
    int find = 5;
    int pos = BinSearch(data, n, find);

    if (pos != -1) {
        printf("Found %d at %d\n", find, pos);
    } else {
        printf("%d not found in the array.\n", find);
    }

    return 0;
}

int BinSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}