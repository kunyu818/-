	#include <stdio.h>
	#include <stdlib.h>
	struct Node {
	    int coefficient;
	    int exponent; 
	    struct Node* next;
	};
	struct Node* createNode(int coeff, int expo) {
	    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	    if (newNode == NULL) {
	        printf("Memory allocation failed.\n");
	        exit(EXIT_FAILURE);
	    }
	    newNode->coefficient = coeff;
	    newNode->exponent = expo;
	    newNode->next = NULL;
	    return newNode;
	}
	void freePolynomial(struct Node* head) {
	    struct Node* temp;
	    while (head != NULL) {
	        temp = head;
	        head = head->next;
	        free(temp);
	    }
	}
	struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
	    struct Node* result = NULL;
	    
	    for (struct Node* term1 = poly1; term1 != NULL; term1 = term1->next) {
	        for (struct Node* term2 = poly2; term2 != NULL; term2 = term2->next) {
	            int coeff = term1->coefficient * term2->coefficient;
	            int expo = term1->exponent + term2->exponent;
	            struct Node* newNode = createNode(coeff, expo);
	            
	            // 插入新节点到结果链表
	            struct Node* temp = result;
	            if (result == NULL || result->exponent < expo) {
	                newNode->next = result;
	                result = newNode;
	            } else {
	                while (temp->next != NULL && temp->next->exponent > expo) {
	                    temp = temp->next;
	                }
	                newNode->next = temp->next;
	                temp->next = newNode;
	            }
	        }
	    }
	    return result;
	}
	void printPolynomial(struct Node* poly) {
	    if (poly == NULL) {
	        printf("0\n");
	        return;
	    }
	    while (poly != NULL) {
	        printf("%dx^%d", poly->coefficient, poly->exponent);
	        poly = poly->next;
	        if (poly != NULL) {
	            printf(" + ");
	        }
	    }
	    printf("\n");
	}
	int main() {
	    struct Node* poly1 = createNode(1, 0);
	    poly1->next = createNode(3, 1);
	    poly1->next->next = createNode(1, 3);
	    poly1->next->next->next = createNode(-4, 7);
	    struct Node* poly2 = createNode(1, 0);
	    poly2->next = createNode(-2, 2);
	    poly2->next->next = createNode(1, 99);
	    struct Node* result = multiplyPolynomials(poly1, poly2);
	    printPolynomial(result);
	    freePolynomial(poly1);
	    freePolynomial(poly2);
	    freePolynomial(result);
	    return 0;
	}

