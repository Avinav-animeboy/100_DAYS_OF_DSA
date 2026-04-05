/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
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
        addEdge(adj, v, u);
    }

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}