#include <stdio.h>
int isWiggleSequence(int nums[], int length) {
    if (length < 2) {
        return 1;
    }
    int prevDiff = 0;
    int count = 0;
    for (int i = 1; i < length; i++) {
        int diff = nums[i] - nums[i - 1];
        if (diff == 0) {
            count++;
        } else if (diff * prevDiff <= 0) {
            prevDiff = diff;
        } else {
            count++;
            prevDiff = diff;
        }
    }
    return count;
}
void testWiggleSequence(int nums[], int length) {
    int result = isWiggleSequence(nums, length);
    if (result == 1) {
        printf("����: ");
        for (int i = 0; i < length; i++) {
            printf("%d ", nums[i]);
        }
        printf("������������ǰڶ����С�\n");
    } else {
        printf("����: ");
        for (int i = 0; i < length; i++) {
            printf("%d ", nums[i]);
        }
        printf("���ǰڶ����У���Ҫɾ�� %d ��Ԫ�ء�\n", result);
    }
}
int main() {
    int test_case_1[] = {1, 7, 4, 9, 2, 5};
    int test_case_2[] = {1, 2, 3, 4, 5};
    testWiggleSequence(test_case_1, sizeof(test_case_1) / sizeof(test_case_1[0]));
    testWiggleSequence(test_case_2, sizeof(test_case_2) / sizeof(test_case_2[0]));
    return 0;
}

