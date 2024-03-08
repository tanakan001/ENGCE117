#include <stdio.h>

int *KnapsackDP(int *w, int *v, int n, int wx) {
    int dp[n + 1][wx + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i - 1] <= j)
                dp[i][j] = (v[i - 1] + dp[i - 1][j - w[i - 1]]) > dp[i - 1][j] ? (v[i - 1] + dp[i - 1][j - w[i - 1]]) : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int *x = new int[n];
    int i = n, j = wx, k = 0;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            x[k++] = 1;
            j -= w[i - 1];
        } else {
            x[k++] = 0;
        }
        i--;
    }

    while (k < n) {
        x[k++] = 0;
    }

    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackDP(w, v, n, wx);

    printf("Output:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", x[i]);

    delete[] x;

    return 0;
}