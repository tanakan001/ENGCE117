#include <stdio.h>

int* Dijkstra(int* L, int n);

int main() {
    int n = 5, i = 0, *d, *g;
    g = new int[n * n];
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100;
    g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;
    g[0 * n + 4] = 10;
    g[1 * n + 2] = 20;
    g[3 * n + 1] = 20;
    g[3 * n + 2] = 20;
    g[4 * n + 3] = 10;

    d = Dijkstra(g, n);
    printf("Shortest paths from vertex 0 to each vertex:\n");
    for (i = 1; i < n; i++)
        printf("%d ", d[i]);
    delete[] g;
    delete[] d;

    return 0;
}

int* Dijkstra(int* L, int n) {
    int* d = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++) {
        d[i] = 2147483647;
        visited[i] = false;
    }

    d[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minDist = 2147483647, u;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && d[v] < minDist) {
                minDist = d[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && L[u * n + v] != -1 &&
                d[u] != 2147483647 && d[u] + L[u * n + v] < d[v]) {
                d[v] = d[u] + L[u * n + v];
            }
        }
    }

    delete[] visited;
    return d;
}