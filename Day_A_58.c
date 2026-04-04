/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    struct Node* node = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end) return node;

    int inIndex = search(inorder, start, end, node->data);

    node->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}