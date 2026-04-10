/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int parent[MAX];
int graph[MAX][MAX];
int n;

int dfs(int v) {
    visited[v] = 1;
    for (int u = 0; u < n; u++) {
        if (graph[v][u]) {
            if (!visited[u]) {
                parent[u] = v;
                if (dfs(u)) return 1;
            } else if (u != parent[v]) {
                return 1;
            }
        }
    }
    return 0;
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
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}