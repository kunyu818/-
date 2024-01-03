#include <stdio.h>
#include <string.h>
void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(char* target, char* pattern) {
    int M = strlen(pattern);
    int N = strlen(target);
    int lps[M];
    computeLPSArray(pattern, M, lps);
    int i = 0;  // Ŀ�괮��ָ��
    int j = 0;  // �Ӵ���ָ��
    while (i < N) {
        if (pattern[j] == target[i]) {
            i++;
            j++;
        }
        if (j == M) {
            printf("�Ӵ���Ŀ�괮�е�λ�ã�%d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != target[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}
int main() {
    char target[] = "ababcabcacbab";
    char pattern[] = "abcac";
    printf("Ŀ�괮: %s\n", target);
    printf("�Ӵ�: %s\n", pattern);
    KMPSearch(target, pattern);
    char target2[] = "hello world";
    char pattern2[] = "world";
    printf("\nĿ�괮: %s\n", target2);
    printf("�Ӵ�: %s\n", pattern2);
    KMPSearch(target2, pattern2);
    return 0;
}

