#include <stdio.h>

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(Item item1, Item item2) {
    return item1.ratio > item2.ratio;
}

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Item items[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (items[j].ratio < items[j + 1].ratio)
                swap(&items[j], &items[j + 1]);
}

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    Item items[n];

    for (int i = 0; i < n; i++) {
        items[i].weight = w[i];
        items[i].value = v[i];
        items[i].ratio = (double)v[i] / w[i];
    }

    bubbleSort(items, n);

    int *x = new int[n];
    for (int i = 0; i < n; i++)
        x[i] = 0;

    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= wx) {
            x[i] = 1;
            currentWeight += items[i].weight;
        }
    }

    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackGreedy(w, v, n, wx);

    printf("Output:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);

    delete[] x;

    return 0;
}