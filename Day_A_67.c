/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

Output:
- A list of vertices in topologically sorted order
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int graph[MAX][MAX];
int n;
int topoOrder[MAX];
int topoIndex = 0;

void dfs(int v) {
    visited[v] = 1;
    for (int u = 0; u < n; u++) {
        if (graph[v][u] && !visited[u]) {
            dfs(u);
        }
    }
    topoOrder[topoIndex++] = v;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0/1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    for (int i = topoIndex - 1; i >= 0; i--) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
    return 0;
}
