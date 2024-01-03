#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return (s->top == -1);
}
int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}
void push(Stack *s, int data) {
    if (!isFull(s)) {
        s->items[++(s->top)] = data;
    }
}
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1;
}
void convert(Stack *s, int decimal, int base) {
    static char hexChars[] = "0123456789ABCDEF";
    if (decimal > 0) {
        int remainder = decimal % base;
        push(s, remainder);
        convert(s, decimal / base, base);
    }
}
void printConversion(Stack *s, int base) {
    static char hexChars[] = "0123456789ABCDEF";
    while (!isEmpty(s)) {
        int digit = pop(s);
        if (base == 16) {
            printf("%c", hexChars[digit]);
        } else {
            printf("%d", digit);
        }
    }
}
int main() {
    int decimal1 = 10;
    int decimal2 = 31;
    Stack s;
    initStack(&s);
    printf("10 %d:\n", decimal1);
    printf("2: ");
    convert(&s, decimal1, 2);
    printConversion(&s, 2);
    printf("\n8: ");
    convert(&s, decimal1, 8);
    printConversion(&s, 8);
    printf("\n16: ");
    convert(&s, decimal1, 16);
    printConversion(&s, 16);
    printf("\n");
    initStack(&s);
    printf("\n10 %d:\n", decimal2);
    printf("2: ");
    convert(&s, decimal2, 2);
    printConversion(&s, 2);
    printf("\n8: ");
    convert(&s, decimal2, 8);
    printConversion(&s, 8);
    printf("\n16: ");
    convert(&s, decimal2, 16);
    printConversion(&s, 16);
    printf("\n");
    return 0;
}

