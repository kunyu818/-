#include <stdio.h>
#include <string.h>
#include <ctype.h>
void f(char* a) {
    int b = 0, c = 0, d = 0;
    for (int e = 0; e < strlen(a); e++) {
        if (!isspace(a[e])) {
            a[b++] = a[e];
            c = 0;
            d = b;
        } else {
            c++;
            if (c == 1) {
                a[b++] = ' ';
            }
        }
    }
    if (b > d && isspace(a[b - 1])) {
        b--;
    }
    a[b] = '\0';
}
int main() {
    char s1[] = "This is an example sentence.";
    printf("输入: \"%s\"\n", s1);
    f(s1);
    printf("输出: \"%s\"\n", s1);
    char s2[] = " Hello world! ";
    printf("\n输入: \"%s\"\n", s2);
    f(s2);
    printf("输出: \"%s\"\n", s2);
    return 0;
}
