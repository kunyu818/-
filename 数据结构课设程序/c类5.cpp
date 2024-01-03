#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createCircularLinkedList() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = -1;
    head->next = head;
    head->prev = head;
    return head;
}
int findElement(struct Node* head, int value) {
    struct Node* current = head->next;
    while (current != head) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void insertElement(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
}
void freeCircularLinkedList(struct Node* head) {
    struct Node* current = head->next;
    while (current != head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}
void intersection(struct Node* setA, struct Node* setB) {
    struct Node* currentA = setA->next;
    while (currentA != setA) {
        if (!findElement(setB, currentA->data)) {
            struct Node* temp = currentA;
            currentA = currentA->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        } else {
            currentA = currentA->next;
        }
    }
}
void unionSet(struct Node* setA, struct Node* setB) {
    struct Node* currentB = setB->next;
    while (currentB != setB) {
        if (!findElement(setA, currentB->data)) {
            insertElement(setA, currentB->data);
        }
        currentB = currentB->next;
    }
}
void printSet(struct Node* head) {
    struct Node* current = head->next;
    printf("{ ");
    while (current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}\n");
}
int main() {
    struct Node* setA = createCircularLinkedList();
    insertElement(setA, 1);
    insertElement(setA, 2);
    insertElement(setA, 3);
    insertElement(setA, 4);
    insertElement(setA, 5);
    struct Node* setB = createCircularLinkedList();
    insertElement(setB, 3);
    insertElement(setB, 4);
    insertElement(setB, 5);
    insertElement(setB, 6);
    insertElement(setB, 7);
    printf("集合A：");
    printSet(setA);
    printf("集合B：");
    printSet(setB);
    printf("交集：");
    intersection(setA, setB);
    printSet(setA);
    printf("并集：");
    unionSet(setA, setB);
    printSet(setA);
    freeCircularLinkedList(setA);
    freeCircularLinkedList(setB);
    return 0;
}

