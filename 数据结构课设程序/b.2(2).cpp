#include <stdio.h>
#include <string.h>
int isPalindrome(char *s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}
void bruteForcePalindrome(char *s) {
    int n = strlen(s);
    int maxLen = 0;
    int startIdx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    startIdx = i;
                }
            }
        }
    }
    printf("最长回文子串为: ");
    for (int i = startIdx; i < startIdx + maxLen; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}
int main() {
    char s[100];
    printf("请输入字符串: ");
    scanf("%s", s);
    bruteForcePalindrome(s);
    return 0;
}

