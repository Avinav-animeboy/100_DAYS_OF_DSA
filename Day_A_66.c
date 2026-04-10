/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int recStack[MAX];
int graph[MAX][MAX];
int n;

int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int u = 0; u < n; u++) {
        if (graph[v][u]) {
            if (!visited[u]) {
                if (dfs(u)) return 1;
            } else if (recStack[u]) {
                return 1;
            }
        }
    }
    recStack[v] = 0;
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
