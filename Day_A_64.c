/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = v;
    n->next = NULL;
    return n;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* n = createNode(v);
    n->next = adj[u];
    adj[u] = n;
}

void bfs(struct Node* adj[], int n, int s) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->val]) {
                visited[temp->val] = 1;
                queue[rear++] = temp->val;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u); // remove for directed
    }

    int s;
    scanf("%d", &s);

    bfs(adj, n, s);

    return 0;
}