#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    int leftIndex;
    int rightIndex;
};
struct TreeNode* buildTree(int n) {
    struct TreeNode* nodes = (struct TreeNode*)malloc(n * sizeof(struct TreeNode));
    for (int i = 0; i < n; ++i) {
        int val, leftIndex, rightIndex;
        scanf("%d %d %d", &val, &leftIndex, &rightIndex);
        nodes[i].val = val;
        nodes[i].leftIndex = leftIndex;
        nodes[i].rightIndex = rightIndex;
    }
    return nodes;
}
void preorderTraversal(struct TreeNode* nodes, int rootIndex) {
    if (rootIndex == -1) return;

    printf("%d ", nodes[rootIndex].val);
    preorderTraversal(nodes, nodes[rootIndex].leftIndex);
    preorderTraversal(nodes, nodes[rootIndex].rightIndex);
}
void inorderTraversal(struct TreeNode* nodes, int rootIndex) {
    if (rootIndex == -1) return;

    inorderTraversal(nodes, nodes[rootIndex].leftIndex);
    printf("%d ", nodes[rootIndex].val);
    inorderTraversal(nodes, nodes[rootIndex].rightIndex);
}
void postorderTraversal(struct TreeNode* nodes, int rootIndex) {
    if (rootIndex == -1) return;

    postorderTraversal(nodes, nodes[rootIndex].leftIndex);
    postorderTraversal(nodes, nodes[rootIndex].rightIndex);
    printf("%d ", nodes[rootIndex].val);
}
int main() {
    int n;
    printf("输入: ");
    scanf("%d", &n);
    struct TreeNode* nodes = buildTree(n);
    printf("前序:\n");
    preorderTraversal(nodes, 0); 
    printf("\n");
    printf("中序:\n");
    inorderTraversal(nodes, 0);
    printf("\n");
    printf("后序:\n");
    postorderTraversal(nodes, 0);
    printf("\n");
    free(nodes);
    return 0;
}

