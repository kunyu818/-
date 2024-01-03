#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}
Node* splitList(Node* head, Node** oddList, Node** evenList) {
    Node* oddHead = NULL;
    Node* evenHead = NULL;
    Node* oddTail = NULL;
    Node* evenTail = NULL;
    int count = 1;
    while (head != NULL) {
        if (count % 2 != 0) { // Odd position node
            if (oddHead == NULL) {
                oddHead = head;
                oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        } else { // Even position node
            if (evenHead == NULL) {
                evenHead = head;
                evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        head = head->next;
        ++count;
    }
    if (oddTail != NULL) oddTail->next = NULL;
    if (evenTail != NULL) evenTail->next = NULL;

    *oddList = oddHead;
    *evenList = evenHead;

    return oddHead;
}
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);
    head1->next->next->next->next->next = createNode(6);
    head1->next->next->next->next->next->next = createNode(7);
    head1->next->next->next->next->next->next->next = createNode(8);
    head1->next->next->next->next->next->next->next->next = createNode(9);
    head1->next->next->next->next->next->next->next->next->next = createNode(10);
    Node* oddList1 = NULL;
    Node* evenList1 = NULL;
    printList(head1);
    splitList(head1, &oddList1, &evenList1);
    printList(oddList1);
    printList(evenList1);
    return 0;
}


