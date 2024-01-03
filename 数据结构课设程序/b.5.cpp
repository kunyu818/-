#include <stdio.h>
#include <stdlib.h>
int countInversions(int arr[], int n) {
    int inversions = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}
int main() {
    int n;
    printf("请输入排列的大小：");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("请输入1-%d的随机排列：", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int inversions = countInversions(arr, n);
    printf("最少步数：%d\n", inversions);
    free(arr);
    return 0;
}

