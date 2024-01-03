#include <stdio.h>
#include <string.h>
#define CHAR_SIZE 256
void generateShiftTable(char* pattern, int patternLength, int shiftTable[]) {
    for (int i = 0; i < CHAR_SIZE; ++i) {
        shiftTable[i] = patternLength + 1;
    }
    for (int i = 0; i < patternLength; ++i) {
        shiftTable[(int)pattern[i]] = patternLength - i;
    }
}
void SundaySearch(char* target, char* pattern) {
    int targetLength = strlen(target);
    int patternLength = strlen(pattern);
    int shiftTable[CHAR_SIZE];
    generateShiftTable(pattern, patternLength, shiftTable);
    int i = 0;
    while (i <= targetLength - patternLength) {
        int j = 0;
        while (j < patternLength && pattern[j] == target[i + j]) {
            j++;
        }
        if (j == patternLength) {
            printf("�Ӵ���Ŀ�괮�е�λ�ã�%d\n", i);
            return;
        }
        if (i + patternLength < targetLength) {
            i += shiftTable[(int)target[i + patternLength]];
        } else {
            break;
        }
    }
    printf("�Ӵ�����Ŀ�괮��\n");
}
int main() {
    char target[] = "ababcabcacbab";
    char pattern[] = "abcac";
    printf("Ŀ�괮: %s\n", target);
    printf("�Ӵ�: %s\n", pattern);
    SundaySearch(target, pattern);
    char target2[] = "hello world";
    char pattern2[] = "world";
    printf("\nĿ�괮: %s\n", target2);
    printf("�Ӵ�: %s\n", pattern2);
    SundaySearch(target2, pattern2);
    return 0;
}

