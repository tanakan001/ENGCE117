#include <stdio.h>

int main() {
    int n = 0;
    int i = 0;
    printf("Number User : ");
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        printf("[%d] Hello world\n", i);
    }
    return 0;
}