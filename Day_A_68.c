/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

Output:
- A list of vertices in topologically sorted order
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int inDegree[MAX];
int graph[MAX][MAX];
int n;

void kahn() {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Order: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (graph[u][v]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0/1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j]) {
                inDegree[j]++;
            }
        }
    }

    kahn();
    return 0;
}
