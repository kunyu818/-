#include <stdio.h>
#include <string.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
void longestPalindrome(char *s) {
    int n = strlen(s);
    if (n <= 1) {
        printf("最长回文子串为: %s\n", s);
        return;
    }
    int P[2 * n + 1];
    memset(P, 0, sizeof(P));
    char t[2 * n + 2];
    t[0] = '@';
    t[1] = '#';
    for (int i = 0; i < n; ++i) {
        t[(i + 1) << 1] = s[i];
        t[((i + 1) << 1) + 1] = '#';
    }
    t[(n + 1) << 1] = '\0';
    int C = 0, R = 0;
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < 2 * n + 1; ++i) {
        int mirr = 2 * C - i;
        if (i < R) {
            P[i] = min(R - i, P[mirr]);
        }
        while (t[i + (1 + P[i])] == t[i - (1 + P[i])]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    int end = start + maxLen - 1;
    printf("最长回文子串为: ");
    for (int i = start; i <= end; ++i) {
        printf("%c", s[i]);
    }
    printf("\n");
}
int main() {
    char s[100];
    printf("请输入字符串: ");
    scanf("%s", s);
    longestPalindrome(s);
    return 0;
}

