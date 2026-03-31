/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for BFS
struct Pair {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Pair queue[1000];
    int front = 0, rear = 0;

    int map[2000][100];  // store nodes per HD
    int count[2000] = {0};

    int offset = 1000; // to handle negative HD
    int minHD = 0, maxHD = 0;

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        int index = hd + offset;

        map[index][count[index]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int index = i + offset;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", map[index][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}