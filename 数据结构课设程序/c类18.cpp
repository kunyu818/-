#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_EXPRESSION_SIZE 100

int getPriority(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; // 未知运算符
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char stack[MAX_EXPRESSION_SIZE];
    int top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i]) || infix[i] == '.') {
            while (isdigit(infix[i]) || infix[i] == '.') {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            top--; // 弹出 '('
        } else {
            while (top != -1 && getPriority(stack[top]) >= getPriority(infix[i])) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

double evaluatePostfix(char* postfix) {
    double stack[MAX_EXPRESSION_SIZE];
    int top = -1;
    char *token = strtok(postfix, " ");
    double operand;

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            operand = atof(token);
            stack[++top] = operand;
        } else {
            double operand2 = stack[top--];
            double operand1 = stack[top--];

            switch (token[0]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("除数不能为零\n");
                        exit(EXIT_FAILURE);
                    }
                    stack[++top] = operand1 / operand2;
                    break;
                case '^':
                    stack[++top] = pow(operand1, operand2);
                    break;
                default:
                    printf("未知运算符: %s\n", token);
                    exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " ");
    }

    return stack[top];
}

int main() {
    char infix[MAX_EXPRESSION_SIZE];
    char postfix[MAX_EXPRESSION_SIZE];

    printf("请输入算术表达式：\n");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    double result = evaluatePostfix(postfix);

    printf("结果: %.3f\n", result);

    return 0;
}

