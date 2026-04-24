/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}
*/
#include <stdio.h>
#include <string.h>

#define MAX_NODES 1000

int visited[MAX_NODES];
int graph[MAX_NODES][MAX_NODES];
int n, m;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int connected_components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            connected_components++;
        }
    }

    printf("%d\n", connected_components);
    return 0;
}
