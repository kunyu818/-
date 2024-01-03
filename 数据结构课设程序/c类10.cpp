#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* findLowestCommonAncestorSeq(TreeNode* root, int i, int j) {
    while (root) {
        if (root->val > i && root->val > j) {
            root = root->left;
        } else if (root->val < i && root->val < j) {
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}
TreeNode* findLowestCommonAncestorTree(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    TreeNode* left = findLowestCommonAncestorTree(root->left, p, q);
    TreeNode* right = findLowestCommonAncestorTree(root->right, p, q);
    if (left && right) {
        return root;
    }
    return (left != NULL) ? left : right;
}
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main() {
    TreeNode* rootSeq = createNode(6);
    rootSeq->left = createNode(2);
    rootSeq->right = createNode(8);
    rootSeq->left->left = createNode(0);
    rootSeq->left->right = createNode(4);
    rootSeq->right->left = createNode(7);
    rootSeq->right->right = createNode(9);
    rootSeq->left->right->left = createNode(3);
    rootSeq->left->right->right = createNode(5);
    int i = 2, j = 8;
    TreeNode* ancestorSeq = findLowestCommonAncestorSeq(rootSeq, i, j);
    printf("顺序存储方式最近公共祖先编号：%d，值：%d\n", ancestorSeq->val, ancestorSeq->val);
    TreeNode* rootTree = createNode(3);
    rootTree->left = createNode(5);
    rootTree->right = createNode(1);
    rootTree->left->left = createNode(6);
    rootTree->left->right = createNode(2);
    rootTree->right->left = createNode(0);
    rootTree->right->right = createNode(8);
    rootTree->left->right->left = createNode(7);
    rootTree->left->right->right = createNode(4);
    TreeNode* p = rootTree->left;
    TreeNode* q = rootTree->left->right->right;
    TreeNode* ancestorTree = findLowestCommonAncestorTree(rootTree, p, q);
    printf("二叉链存储方式最近公共祖先编号：%d，值：%d\n", ancestorTree->val, ancestorTree->val);
    return 0;
}

