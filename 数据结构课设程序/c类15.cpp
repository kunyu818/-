#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *newNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bool isFullBinaryTree(struct TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if (root->left && root->right) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }
    return false;
}
bool isCompleteBinaryTree(struct TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    struct TreeNode *queue[1000];
    int front = 0, rear = 0;
    bool flag = false;
    queue[rear++] = root;
    while (front < rear) {
        struct TreeNode *node = queue[front++];
        
        if (node) {
            if (flag) {
                return false;
            }
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        } else {
            flag = true;
        }
    }
    return true;
}
int main() {
    struct TreeNode *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    struct TreeNode *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    root2->right->left = newNode(6);
    root2->right->right = newNode(7);
    bool fullTree = isFullBinaryTree(root2);
    bool completeTree = isCompleteBinaryTree(root2); 
    printf("满二叉树: %s\n", fullTree ? "true" : "false");
    printf("完全二叉树: %s\n", completeTree ? "true" : "false");
    return 0;
}

