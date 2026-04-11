/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int dist[MAX_VERTICES];
int parent[MAX_VERTICES];
int n, m;

void initialize_single_source(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;
}

int relax(int u, int v, int w) {
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        return 1;
    }
    return 0;
}

int bellman_ford(int source) {
    initialize_single_source(source);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            relax(edges[j].u, edges[j].v, edges[j].w);
        }
    }
    // Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        if (relax(edges[j].u, edges[j].v, edges[j].w)) {
            return 0;  // Negative cycle detected
        }
    }
    return 1;  // No negative cycle
}

void print_solution() {
    printf("Vertex\tDistance from Source\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
        if (dist[i] == INT_MAX) {
            printf("INF\t\t\t");
        } else {
            printf("%d\t\t\t", dist[i]);
        }
        // Print path
        int p = parent[i];
        while (p != -1) {
            printf("%d ", p);
            p = parent[p];
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    if (bellman_ford(source)) {
        print_solution();
    } else {
        printf("Negative weight cycle detected.\n");
    }
    return 0;
}
