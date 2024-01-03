#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};
bool isSubsequence(struct Node* A, struct Node* B) {
    if (A == NULL && B == NULL) {
        return true; 
    }
    if (A == NULL || B == NULL) {
        return false; 
    }

    if (A->value == B->value) {
        return isSubsequence(A->next, B->next); 
    } else {
        return isSubsequence(A->next, B);
    }
}
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* A_head = createNode(1);
    A_head->next = createNode(2);
    A_head->next->prev = A_head;
    A_head->next->next = createNode(3);
    A_head->next->next->prev = A_head->next;
    A_head->next->next->next = createNode(4);
    A_head->next->next->next->prev = A_head->next->next;
    A_head->next->next->next->next = createNode(5);
    A_head->next->next->next->next->prev = A_head->next->next->next;

    struct Node* B_head = createNode(2);
    B_head->next = createNode(4);
    B_head->next->prev = B_head;
    bool result = isSubsequence(A_head, B_head);
    if (result) {
        printf("是子序列\n");
    } else {
        printf("不是子序列\n");
    }
    freeList(A_head);
    freeList(B_head);
    return 0;
}

