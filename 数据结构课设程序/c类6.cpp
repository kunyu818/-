#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct {
    char items[MAX_SIZE];
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
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = c;
    }
}
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}
int isValidStackSequence(char sequence[], char charset[]) {
    int sequenceLength = strlen(sequence);
    int charsetLength = strlen(charset);
    Stack s;
    initStack(&s);
    int charsetIndex = 0;
    for (int i = 0; i < sequenceLength; ++i) {
        while (charsetIndex < charsetLength && charset[charsetIndex] != sequence[i]) {
            push(&s, charset[charsetIndex]);
            charsetIndex++;
        }
        if (!isEmpty(&s) && s.items[s.top] == sequence[i]) {
            pop(&s);
        } else {
            return 0;
        }
    }
    return isEmpty(&s) && charsetIndex == charsetLength;
}
int main() {
    char charset[] = "abcde";
    char sequence1[] = "edcba";
    char sequence2[] = "abcde";
    if (isValidStackSequence(sequence1, charset)) {
        printf("%s 是合法的出栈序列\n", sequence1);
    } else {
        printf("%s 不是合法的出栈序列\n", sequence1);
    }
    if (isValidStackSequence(sequence2, charset)) {
        printf("%s 是合法的出栈序列\n", sequence2);
    } else {
        printf("%s 不是合法的出栈序列\n", sequence2);
    }
    return 0;
}

