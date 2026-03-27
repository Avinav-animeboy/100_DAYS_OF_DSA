/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

// Build tree
struct Node* build(int a[], int n) {
    if (n == 0 || a[0] == -1) return NULL;

    struct Node* root = newNode(a[0]);
    struct Node* q[n];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* cur = q[f++];

        if (i < n && a[i] != -1) {
            cur->left = newNode(a[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && a[i] != -1) {
            cur->right = newNode(a[i]);
            q[r++] = cur->right;
        }
        i++;
    }

    return root;
}

// Inorder
void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    struct Node* root = build(a, n);
    inorder(root);

    return 0;
}