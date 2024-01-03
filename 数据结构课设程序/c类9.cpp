#include <stdio.h>
#include <string.h>
#include <ctype.h>
void formatSentence(char* sentence) {
    int length = strlen(sentence);
    int index = 0;
    int spaceCount = 0;
    int start = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(sentence[i])) {
            sentence[index++] = sentence[i];
            spaceCount = 0;
            start = index;
        } else {
            spaceCount++;
            if (spaceCount == 1) {
                sentence[index++] = ' ';
            }
        }
    }
    if (index > start && isspace(sentence[index - 1])) {
        index--;
    }
    sentence[index] = '\0';
}
int main() {
    char sentence1[] = "This is an example sentence.";
    printf("输入: \"%s\"\n", sentence1);
    formatSentence(sentence1);
    printf("输出: \"%s\"\n", sentence1);
    char sentence2[] = " Hello world! ";
    printf("\n输入: \"%s\"\n", sentence2);
    formatSentence(sentence2);
    printf("输出: \"%s\"\n", sentence2);
    return 0;
}

