/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void levelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* curr = queue[front++];

        printf("%d ", curr->val);

        if (curr->left != NULL)
            queue[rear++] = curr->left;

        if (curr->right != NULL)
            queue[rear++] = curr->right;
    }
}
