/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX], dist[MAX], n;

void dijkstra(int src) {
    int visited[MAX] = {0};
    for (int i = 0; i < n; i++) {
        dist[i] = graph[src][i];
    }
    dist[src] = 0;
    visited[src] = 1;

    for (int count = 1; count < n; count++) {
        int u = -1, minDist = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    dijkstra(src);

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("To %d: INF\n", i);
        } else {
            printf("To %d: %d\n", i, dist[i]);
        }
    }
    return 0;
}
