#include <stdio.h>
#include <stdlib.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int findPath(struct Node* root, char path[], char target) {
    if (root == NULL)
        return 0;
    path[0] = root->data;
    path++;
    if (root->data == target) {
        *path = '\0';
        return 1;
    }
    if (findPath(root->left, path, target) || findPath(root->right, path, target))
        return 1;
    path--;
    return 0;
}
void printPath(struct Node* root, char target) {
    char path[100];
    if (findPath(root, path, target))
        printf("'%c': %s\n", target, path);
    else
        printf("'%c'\n", target);
}
int main() {
    struct Node* root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('F');
    printPath(root, 'F');
    printPath(root, 'G'); 
    return 0;
}

