/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define INF 999999

int graph[MAX_NODES][MAX_NODES];
int n, m;

void prim() {
    int selected[MAX_NODES] = {0};
    int min_edge[MAX_NODES];
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        min_edge[i] = INF;
    }

    min_edge[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!selected[i] && (u == -1 || min_edge[i] < min_edge[u])) {
                u = i;
            }
        }

        selected[u] = 1;
        total_weight += min_edge[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !selected[v]) {
                min_edge[v] = graph[u][v] < min_edge[v] ? graph[u][v] : min_edge[v];
            }
        }
    }

    printf("%d\n", total_weight);
}

int main() {
    scanf("%d %d", &n, &m);
    memset(graph, 0, sizeof(graph));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    prim();

    return 0;
}
